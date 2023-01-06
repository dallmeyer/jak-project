import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

public class SimpleHTTPServer {
    public static String userAgent;

    public static String xPos1 = "0.0";
    public static String yPos1 = "0.0";
    public static String zPos1 = "0.0";

    public static String xPos2 = "0.0";
    public static String yPos2 = "0.0";
    public static String zPos2 = "0.0";

    public static void main(String args[]) throws IOException {

        ServerSocket server = new ServerSocket(27091);
        System.out.println("Listening for connection on port " + InetAddress.getLocalHost() + " " + server.getLocalPort() +"....");
        while (true) {
            try (Socket client = server.accept()) {
                System.out.println("Debug: got new message: " + client.toString());
                InputStreamReader isr = new InputStreamReader(client.getInputStream());
                BufferedReader br = new BufferedReader(isr);
                StringBuilder request = new StringBuilder();
                String line;
                line = br.readLine();

                while(!line.isBlank()){
                    request.append(line + "\r\n");
                    line = br.readLine();

                    if(line.contains("User-Agent")){
                        userAgent = line;
                    }
                    if(line.contains("X1POS")){
                        xPos1 = line.replace("X1POS:","");
                    }
                    if(line.contains("Y1POS")){
                        yPos1 = line.replace("Y1POS:","");
                    }
                    if(line.contains("Z1POS")){
                        zPos1 = line.replace("Z1POS:","");
                    }

                    if(line.contains("X2POS")){
                        xPos2 = line;
                    }
                    if(line.contains("Y2POS")){
                        yPos2 = line;
                    }
                    if(line.contains("Z2POS")){
                        zPos2 = line;
                    }
                }
                System.out.println(request);

                String httpResponse = "HTTP/1.1 200 OK\r\n\r\n" +" " +
                        "\nJAK POSITIONS" +
                        "\nX1:"+xPos1+"" +
                        "\nY1:"+yPos1+"" +
                        "\nZ1:"+zPos1+"" +
                        "\nFish game done?: No" +
                        "\n\nJAK2 POSITIONS"+
                        "\nX2:"+xPos2+"" +
                        "\nY2:"+yPos2+"" +
                        "\nZ2:"+zPos2+"" +
                        "\nFish game done?: No" +
                        "\n"+userAgent;
                OutputStream clientOutputStream = client.getOutputStream();

                        clientOutputStream.write(httpResponse.getBytes("UTF-8"));
                        clientOutputStream.flush();
                        client.close();

            }
        }
    }
}