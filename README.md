# micro gedre
O que fazer:

## 1° Ler o datasheet do 579-PIC16F1769-I/SS

### Ver os componentes que tenho que colocar ao redor do chip
- [ ] Anotações
- Pinagem na pg(4)
- Applications: Switch-mode power supplies (DC-to-DC/AC-to-DC)
- Tensão de alimentação - 2.5 V to 5.5 V
#### classificações maximas absolutas pg(478)

### Anotações do que achei na pg(462)
#### Five pins are needed for ICSP™ programming:
- obs: (rafael) eu falei com o renan e realmente, é nessa pagina que esta os pinos de conecção para o pickit, alias ele me passou um desenho bem como um esquematico sobre o que mais ou menos ele esta desejando para ser feito deixei anotações sobre isso nos links
- ICSPCLK
- ICSPDAT
- MCLR/VPP
- VDD
- VSS

- [ ] Links
      
- site do fabricante: <https://br.mouser.com/ProductDetail/Microchip-Technology/PIC16F1769-I-SS?qs=4f%252Bx0JRcgJZxCFgtF0sYlg%3D%3D&srsltid=AfmBOooehqHrvz6JPwbJgqptTAqiJM8v0NAbV50qgQvy_N7ubH63BWmr>
  
- datasheet: <https://br.mouser.com/datasheet/2/268/PIC16(L)F1764-5-8-9-14-20-Pin-8-Bit-Flash-MCU-4000-1314189.pdf> (obs: esse daqui não possui typical circuit) / professor falou que
na parte da conecção com o debugger aparece o esquematico, acho que é o da pg(462), é literalmente o mesmo chip, mesma estrutura

- “ For more information on ICSP™ refer to the 'PIC16(L)F170X Memory Programming Specification'”: <https://ww1.microchip.com/downloads/en/DeviceDoc/40001683B.pdf>

- datasheet que o professor passou em que mostra um circuito que exemplifica o que ele quer, se encontra dentre os circuitos da pg(19) (é o circuito conectado ao chip u4 do lado do led d2 green que alias o professor pediu para adicionar tambem para ver se a placa esta ou não ligada): <https://ww1.microchip.com/downloads/en/DeviceDoc/Curiosity-Low-Pin-Count-Development-Board-Users-Guide-40001804D.pdf>
  
## 2° Ler o datasheet do microship pickit 5
### Ver os conectores que tenho que colocar no gravador/depurador + os sinais que ele emite
- [ ] Anotações
- [ ] Links
- site do fabricante: <https://www.microchip.com/en-us/development-tool/PG164150>
- datasheet: <https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/UserGuides/MPLAB-PICkit-5-In-Circuit-Debugger-Users-Guide-50003525.pdf#page=13&zoom=100,0,253>

## links extras:
- "From Idea to Schematic to PCB - <How to do it easily!": https://youtu.be/35YuILUlfGs?si=2a0s9VaXoEdnJa0E>
- "PCB Creation for Beginners - Start to finish tutorial in 10 minutes" <https://youtu.be/MsdJgEinb34?si=JU-Bc_eQL__jkyqd>
- "How To Read A Datasheet - Phil's Lab #123": <https://youtu.be/1EXXqWweTkI?si=hWDz0JQ2FpIgRCck>

## Link do atlium 365:
- <https://rafael-braga.365.altium.com/designs/48A20566-C84B-444C-935F-0ABE2ABFE986#design>

## Obs:
- O circuito do micro deve ser padronizado para os outros bucks
- [ ] ver como vai ser os outros bucks
- [ ] ver quais componentes são controlados pelo micro 

## todo

- [ ] achar uma biblioteca para colocar no altium, para fazer o circuito (achado na página 19 no 4° link)











