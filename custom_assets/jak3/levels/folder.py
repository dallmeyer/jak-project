import shutil
import os

levels = [
    ["orbs-rubblea", "01"],
    ["orbs-rubblea2", "02"],
    ["orbs-rubbleb", "03"],
    ["orbs-rubblec", "04"],
    ["orbs-rublcst", "05"],
    ["orbs-precurd", "06"],
    ["orbs-precurc", "07"],
    ["orbs-precurb", "08"],
    ["orbs-precura", "09"],
    ["orbs-minec", "10"],
    ["orbs-mineb", "11"],
    ["orbs-minea", "12"],
    ["orbs-mined", "13"],
    ["orbs-freehq", "14"],
    ["orbs-lfacrm1", "15"],
    ["orbs-wasdoors", "16"],
    ["orbs-gungame", "17"],
    ["orbs-halfpipe", "18"],
    ["orbs-foresta", "19"],
    ["orbs-forestb", "20"],
    ["orbs-ctyindb", "21"],
    ["orbs-ctyinda", "22"],
    ["orbs-ctygenb", "23"],
    ["orbs-mhcityb", "24"],
    ["orbs-mhcitya", "25"],
    ["orbs-towerb", "26"],
    ["orbs-ltowera", "27"],
    ["orbs-ltowerb", "28"],
    ["orbs-nsta", "29"],
    ["orbs-nstb", "30"],
    ["orbs-templea", "31"],
    ["orbs-templex", "32"],
    ["orbs-templec", "33"],
    ["orbs-templed", "34"],
    ["orbs-templeb", "35"],
    ["orbs-hiphog", "36"],
    ["orbs-ctyslumc", "37"],
    ["orbs-ctyslumb", "38"],
    ["orbs-powergd", "40"],
    ["orbs-ctyport", "41"],
    ["orbs-vinroom", "42"],
    ["orbs-sewl", "43"],
    ["orbs-sewm", "44"],
    ["orbs-sewn", "45"],
    ["orbs-sewo", "46"],
    ["orbs-sewk", "47"],
    ["orbs-sewg", "48"],
    ["orbs-sewh", "49"],
    ["orbs-sewi", "50"],
    ["orbs-sewj", "51"],
    ["orbs-sewb", "52"],
    ["orbs-sewc", "53"],
    ["orbs-sewd", "54"],
    ["orbs-sewe", "55"],
    ["orbs-ctysluma", "57"],
    ["orbs-wascitya", "58"],
    ["orbs-wascityb", "59"],
    ["orbs-wasstada", "60"],
    ["orbs-waspala", "61"],
    ["orbs-stadium", "62"],
    ["orbs-stadiumb", "63"],
    ["orbs-comba", "64"],
    ["orbs-combn", "65"],
    ["orbs-combb", "66"],
    ["orbs-combc", "67"],
    ["orbs-combd", "68"],
    ["orbs-combe", "69"],
    ["orbs-railx", "70"],
    ["orbs-railb", "71"],
    ["orbs-railb2", "72"],
    ["orbs-railc", "73"],
    ["orbs-raild", "74"],
    ["orbs-raile", "75"],
    ["orbs-railf", "76"],
    ["orbs-deswalk", "77"],
    ["orbs-wasstadb", "78"],
    ["orbs-volcanoa", "79"],
    ["orbs-volcanox", "80"],
    ["orbs-lfacrm2", "81"],
    ["orbs-factoryd", "82"],
    ["orbs-factoryb", "83"],
    ["orbs-factoryc", "84"],
    ["orbs-desert", "85"],
    ["orbs-desertd", "86"],
    ["orbs-desertb", "87"],
    ["orbs-deserta", "88"],
    ["orbs-desertf", "89"],
    ["orbs-deserth", "90"],
    ["orbs-desertg", "91"],
    ["orbs-deserte", "92"],
    ["orbs-desertc", "93"],
    ["orbs-sewf", "94"],
]

d = "C:/Users/matt/Documents/Projects/OG-OrbHunt/custom_assets/jak3/levels/"

counter = 296
for x in levels:
    # p = os.path.join(d, x[0])

    # os.mkdir(p)
    # o = p+"/"+x[0]+".gd"
    # shutil.copyfile(d+"orbs-o00/orbs-o00.gd", o)
    # with open(o, 'r') as file:
    #     data = file.read()
    # data = data.replace('xxx', x[0])
    # data = data.replace('O00', "O"+x[1])
    # data = data.replace('o00', "o"+x[1])
    # with open(o, 'w') as file:
    #     file.write(data)

    # o = p+"/"+x[0]+".jsonc"
    # shutil.copyfile(d+"orbs-o00/orbs-o00.jsonc", o)
    # with open(o, 'r') as file:
    #     data = file.read()
    # data = data.replace('xxx', x[0])
    # data = data.replace('O00', "O"+x[1])
    # data = data.replace('o00', "o"+x[1])
    # data = data.replace('"base_id": 100000,', '"base_id": 1' + x[1] + '000,')
    
    # with open(o, 'w') as file:
    #     file.write(data)

    # o = p+"/"+x[0]+".glb"
    # shutil.copyfile(d+"orbs-o00/orbs-o00.glb", o)

    # (build-custom-level "orbs-o00")
    # (custom-level-cgo "O00.DGO" "orbs-o00/orbs-o00.gd")

    # print(f'(build-custom-level "{x[0]}")')
    # print(f'(custom-level-cgo "O{x[1]}.DGO" "{x[0]}/{x[0]}.gd")')
    # print()

    # (define orbs-o00  (orbs-borrow-level #x128 'orbs-o00   'orbs-o00-vis   'o00 'update-mood-default))  ;; wascitya
    
    print(f"(define {x[0]} (orbs-borrow-level {counter} '{x[0]} '{x[0]}-vis 'o{x[1]} 'update-mood-default))")
    counter += 1

for x in reversed(levels):
    print(f"(cons! *level-load-list* '{x[0]})")
