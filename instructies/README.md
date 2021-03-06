# Intructies voor de Arduino Klok Coder Dojo
## Code en Simulatie
### Vervolledig het project uit in de wokwi simulator:
https://wokwi.com/projects/326872404161725010
- Eerst moet je de draden goed trekken, probeer daarvoor ook wat in de wokwi documentatie te lezen door op een onderdeel te klikken en dan op het vraagtekentje
- Probeer het uit, als de draden goed aangesloten is zou de Dag en seconden al weergegeven moeten worden.
- Om de draden de gewenste kleur te geven, moet je naar de diagram.json file gaan en daar de kleuren aanpassen.
- Vul op de plaatsen met TODO de nodige code in om de klok te vervolledigen.
- Speel een beetje met bedrading en mogelijks met code.
- Test het instellen van de clock uit door de rtc.adjust lijn naar keuze te activeren. bvb: `// rtc.adjust(DateTime(2022, 3, 22, 23, 37, 0));`
- Probeer eens de dag weg te laten
- Probeer eens de dag onder te tijd te zetten
- Werkend project in de simulator kan je hier vinden: https://wokwi.com/projects/327233707566957140
## Echte Arduino
Nu we gezien hebben hoe de code werkt en de bedrading hebben kunnen inspecteren in een virtuele omgeving, gaan we de arduino installatie in het echt doen.
### Headers solderen
Je begeleider zal je laten zien hoe headers op een arduino gesoldeerd worden. De begeleider zal ook inschatten of het een goed idee is om je zelf eens te laten proberen.
Belangrijk hier is het gebruik van de de afzuigkap om alle dampen weg te zuigen.
### Adruino bedrading.
**Opgelet: Laat je bedrading altijd eerst nog door een begeleider nakijken!**, zo voorkom je kapotte onderdelen.-\
- Knip de voorzien draadjes op maat zodat ze mooi uitkomen zoals de foto hieronder. Hier hoort ook wat wire stripping bij.
- Sluit de bedrading aan zoals het ook in de WokWi simulator is aangesloten.
  ![res/arduino-clock-schema.png](res/arduino-clock-schema.png)\
- Of je kan je ook baseren op de volgende foto:\
  ![res/arduino-clock-real-wiring-front.jpg](res/arduino-clock-real-wiring-front.jpg)

### Arduino IDE instellen
Als eerste stap moeten we de juiste bibliotheken inladen in de Arduino IDE. Volg daar voor de gifs hieronder:
#### LCD Scherm en klok libraries
![install-arduino-libs.gif](res/install-arduino-libs.gif)
#### Arduino Nano Every Installatie
![install-arduino-nano-every.gif](res/install-arduino-nano-every.gif)

### Code naar echte Arduino schrijven
Nu de arduino ide de juiste onderdelen ingeladen heeft kunnen we verder gaan met de code in te laden en dan naar de arduino te schrijven. 
Hieronder de stappen.
#### Code kopieren
- Creer een nieuw bestand via File -> New.
- Kopieer de code van uit het (wokwi simulator project)[https://wokwi.com/projects/326872404161725010] (of van [hier](../src/rtc_ssd1306_clock.ino)) naar da arduino IDE.
- Vervang alle code in het bestand met de gekopieerde code.
### Arduino aansluiten.
Nu is bijna alles klaar om de code te installeren, maar om dat te doen moeten we natuurlijk wel de Arduino nog aansluiten op de computer via usb.
Doe dit **nadat een begeleider de bedrading nagekeken heeft**

### Com poort selecteren en Code Wegschrijven
Nu moet je nog de juiste com poort selecteren en de code wegschrijven volg daarvoor de onderstaande Gif. Tips:
- Het nummer van de COM poort kan bij idereen anders zijn, selecteer de Com-poort met tussen haakjes `Arduino Nano Every`)
- Je moet daar na op het pijltje klikken.
![install-arduino-nano-every.gif](res/install-arduino-select-com-port-upload.gif)

### Tijd corrigeren.
Het zal je waarschijnlijk opvallen dat de klok nog niet juist staat. Om dat op te lossen moeten we hetvolgende doen:
- Verander in de code 
  ``` 
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  ```
  naar 
  ``` 
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  ```
- Deploy de code (klik op het pijltje in de IDE linksboven)
- Verander de code terug, dus:

  ``` 
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  ```
  terug naar 
  ``` 
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  ```
  - Deploy de code opnieuw(klik op het pijltje in de IDE linksboven)

## Staander Lasercutten
Nu wel alles werkend hebben kunnen we nog een staander lasercutten zodat we het recht kunnen zetten.
Hieronder is het design. De begeleider zal dit samen met jou lasercutten. Als er nog tijd over is kan je ook het design nog aanpassen met [inkscape](https://inkscape.org/).
![res/arduino-stand-cut-kolab.svg](res/arduino-stand-cut-kolab.svg)

## Finale Resultaat
Wanneer de staander ineengezet is kan je de breadbords er op plakken.
Het finale resultaat zou er ongeveer zo moeten uitzien:
![res/arduino-clock-result.svg](res/arduino-clock-result.jpg)
