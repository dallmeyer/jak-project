/*
 *    Copyright (c) <2002-2005> <Jean-Philippe Barrette-LaPierre>
 *    
 *    Permission is hereby granted, free of charge, to any person obtaining
 *    a copy of this software and associated documentation files 
 *    (curlpp), to deal in the Software without restriction, 
 *    including without limitation the rights to use, copy, modify, merge,
 *    publish, distribute, sublicense, and/or sell copies of the Software,
 *    and to permit persons to whom the Software is furnished to do so, 
 *    subject to the following conditions:
 *    
 *    The above copyright notice and this permission notice shall be included
 *    in all copies or substantial portions of the Software.
 *    
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 *    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 *    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 *    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 *    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 *    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
* \file
* Simple POST demo.
* 
*/


#include <cstdlib>
#include <cerrno>


#include "..\third-party\curlpp\include\curlpp\cURLpp.hpp"
#include "..\third-party\curlpp\include\curlpp\Easy.hpp"
#include "..\third-party\curlpp\include\curlpp\Options.hpp"
#include "..\third-party\curlpp\include\curlpp\Exception.hpp"
#include "..\third-party\curlpp\include\curlpp\Infos.hpp"
static const char *pCACertFile = "curl-ca-bundle.crt";


void get_rpc(char* url) {

  using namespace curlpp::options;

    try {
      // That's all that is needed to do cleanup of used resources (RAII style).
      curlpp::Cleanup myCleanup;

      // Our request to be sent.
      curlpp::Easy myRequest;
      

        /* set the cert for client authentication */
      myRequest.setOpt<curlpp::Options::SslCert>(pCACertFile);
      myRequest.setOpt<curlpp::options::CaInfo>(pCACertFile);
      // Set the URL.
  
 
      myRequest.setOpt<curlpp::options::Url>(url);
      myRequest.setOpt<curlpp::options::HttpGet>("xpos1");

      // Send request and get a result.
      // By default the result goes to standard output.
      myRequest.perform();

    std::string effURL;
   
		curlpp::infos::EffectiveUrl::get(myRequest, effURL);
		std::cout << "Effective URL: " << effURL << std::endl;
    }

    catch (curlpp::RuntimeError& e) {
      std::cout << e.what() << std::endl;
    }

    catch (curlpp::LogicError& e) {
      std::cout << e.what() << std::endl;
    }

    return;
  

}



void post_rpc(char* url) {
char *data = NULL;

data = (char*) "dasjhdlksjajhfljkdhljds";
	int size = strlen(data);

	char buf[50];
	try
	{
	

		std::list<std::string> headers;
		headers.push_back("Accept: text/html");
                headers.push_back("X1POS:-2312.234");
                headers.push_back("Y1POS:12.4535");
                headers.push_back("Z1POS:32.3478");
		sprintf(buf, "Content-Length: %d", size); 
		headers.push_back(buf);
    curlpp::Cleanup cleaner;
    curlpp::Easy request;
    
    request.setOpt(new curlpp::options::Url(url)); 
    request.setOpt(new curlpp::options::Verbose(true)); 
    
    std::list<std::string> header; 
    header.push_back("Content-Type: application/octet-stream"); 
    request.setOpt<curlpp::Options::SslCert>(pCACertFile);
    request.setOpt<curlpp::options::CaInfo>(pCACertFile);
    request.setOpt<curlpp::options::HttpHeader>(header); 
    request.setOpt<curlpp::options::HttpHeader>(headers);
    
    request.setOpt<curlpp::options::PostFields>("abcd");
    request.setOpt<curlpp::options::PostFieldSize>(5);
    request.setOpt<curlpp::options::Post>(true);
    
    request.perform();

  }
  catch (curlpp::LogicError & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (curlpp::RuntimeError & e)
	{
		std::cout << e.what() << std::endl;
	}

  

  return;
}




