#include "rapidJson/writer.h"
#include "rapidJson/stringbuffer.h"
#include "rapidJson/filereadstream.h"
#include "rapidJson/filewritestream.h"
#include "rapidJson/document.h"
#include <iostream>

void ScoreUpdater(std::string Username, std::string Password, int NewBestScore)
{
    using namespace rapidjson;
    FILE* fp = fopen("C:/Users/super/Desktop/progetto-scuola-2020/Users/Users.json", "rb"); //Apro il file json
    if(!fp) std::cout << "\nErrore di apertura del file..."; //Nel caso non si apra dare un errore
    char buf[0XFFFF]; //Inizializzo il buffer ad un numero altissimo
    FileReadStream input(fp, buf, sizeof(buf)); //Creo una stream (vuota) con la grandezza del buffer
    Document UserDoc;
    UserDoc.ParseStream(input); //Parso il file json dentro ad un documento
    fclose(fp);

    const Value& Users = UserDoc; //Creo un "Value" per iterare l'array json
    assert(Users.IsArray()); //Controllo che il valore sia un array

    for (rapidjson::Value::ConstValueIterator Itr = Users.Begin(); Itr != Users.End(); ++Itr) //Itero l'array grazie al "Value" Users
    { 
        const Value& username = (*Itr)["Username"];
        const Value& password = (*Itr)["Password"];
        const Value& bestScore = (*Itr)["BestScore"];

        if(username.GetString() == Username && password.GetString() == Password) //Cerco dentro all'array l'utente che ha fatto l'accesso prima
        {
            //Cambio lo score precedente con quello nuovo
            Document d;
            Document::AllocatorType& a = d.GetAllocator();

            //Mi salvo tutte le caratteristiche dell'utente e cambio il BestScore
            Value data(kObjectType);
            Value tempUsername;;
            Value tempPassword;
            Value tempBestScore;

            tempUsername.SetString(username.GetString(), a); //Metto la stringa con l'username in "tempUsername" con l'allocator di d
            tempPassword.SetString(password.GetString(), a); //Metto la stringa con la password in "value2" con l'allocator di d
            tempBestScore.SetInt(NewBestScore); //Metto la stringa con il best score(0) con l'allocator di d
            
            data.AddMember("Username", tempUsername, a); //Aggiungo l'username all'oggetto "data"
            data.AddMember("Password", tempPassword, a); //Aggiungo la password all'oggetto "data"
            data.AddMember("BestScore", tempBestScore, a); //Aggiungo il BestScore all'oggetto "data"

            UserDoc.Erase(Itr); //Tolgo le caratteristiche dell'utente (vecchie)

            UserDoc.PushBack(data, UserDoc.GetAllocator()); //Metto le 3 nuove caratteristiche dell'utente dentro al doc

            FILE* outfile = fopen("C:/Users/super/Desktop/progetto-scuola-2020/Users/Users.json", "wb"); //Scrivo il file
            char writeBuffer[65536]; //Creo il buffer dove ci metterò la stream
            FileWriteStream os(outfile, writeBuffer, sizeof(writeBuffer)); //Metto tutto in un FileWriteStream

            Writer<FileWriteStream> writer(os); //Uso un writer per parsarlo nel documento
            UserDoc.Accept (writer); //Metto il buffer parsato nel documento
            fclose(outfile);
            break;
        }
    }
}




    //NON RIESCO A CAPIRE COME SI ITERIZZA UN ARRAY IN QUELLA MERDA DI RAPIDJSON DIOMMMERDA
    //CERTO CHE POTEVANO FARE UNA REPO IN CUI SI CAPISCA QUALCOSA
    //C'E', SI CAPISCE, MA PORCODDIO NON SONO NELLA LORO TESTA
    //VA BEH HO CAPITO SONO UN RITARDATO
    //DOVREBBERO FARE UN'ALTRA REPO DOVE RISPIEGANO TUTTO COME SE DOVESSERO PARLARE AD UN AUTISTICO