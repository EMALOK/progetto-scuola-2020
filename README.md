## Setup su windows con MinGW

 1. Clonare la repository
    
    `> git clone https://github.com/EMALOK/progetto-scuola-2020.git`
 
 2. Installare SFML

    Controlla la versione di g++ e scarica la corretta versione di [SFML](https://www.sfml-dev.org)

    `> g++ -v`

    Estrarre la cartella e posizionarla nel disco C:\\, rinominarla "SFML"
 
 3. Installare Make
 
    Installare [Make for Windows](http://gnuwin32.sourceforge.net/packages/make.htm)

4. Includere i .dll necessari

	Creare una cartella `build` all'interno del progetto
	
	Copiare tutti i .dll contenuti in `C:\SFML\bin` all'interno della cartella build
	
	Copiare i .dll `libgcc_s_dw2-1.dll` e `libstdc++-6.dll` contenuti in `C:\MinGW\bin` all'interno della cartella build
	
 5. Compilazione
 
	 Compilare con Make
     
	 `> make`
	 
	 L'esecutibile sarà generato all'interno della cartella `build`
	 
	 appunti su jamboard
https://jamboard.google.com/d/1rosZrcKeH_THEa587HVlwblJFedYjjiJiXavM-9PbL0/viewer?f=3

[Video](https://youtu.be/OTcojesdycY)
