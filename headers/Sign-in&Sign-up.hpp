#include "Button.hpp"
#include "Textbox.hpp"
#include <SFML/Graphics.hpp>
#include "rapidJson/writer.h"
#include "rapidJson/stringbuffer.h"
#include "rapidJson/filereadstream.h"
#include "rapidJson/filewritestream.h"
#include "rapidJson/document.h"
#include <iostream>

#define HEIGH 900
#define WIDTH 900
#define ERRORS_SIGN_IN_Y_DEF 700
#define ERRORS_SIGN_IN_Y_OFF 10

bool LenghtError = false;
bool SpecCharError = false;
bool NumError = false;
bool CapError = false;
bool EqError = false;
bool ClosedWindow = false;

int BestScore;
std::string Username;
std::string Password;

bool Sign_up(std::string Username, std::string Password)
{
    FILE* fp = fopen("./Users/Users.json", "rb");
    if(!fp) std::cout << "\nErrore di apertura del file...";
    char buf[0XFFFF];
    rapidjson::FileReadStream input(fp, buf, sizeof(buf));
    rapidjson::Document mapDoc;
    mapDoc.ParseStream(input);
    fclose(fp);

    for(auto& v : mapDoc.GetArray())// if(p["Username"].GetString() == Username && p["Password"].GetString() == Password) //Loppa in tutti gli utenti e se ne trova 1 che combacia lo fa loggare
    {
        if(v["Username"].GetString() == Username && v["Password"].GetString() == Password) //Loppa in tutti gli utenti e se ne trova 1 che combacia lo fa loggare
        {
            BestScore = v["BestScore"].GetInt();
            return true;
        }
    }
    return false; //Altrimenti fa rimettere le credenziali
}

void Sign_in(std::string Username, std::string Password)
{
    using namespace rapidjson;

    FILE* fp = fopen("./Users/Users.json", "rb"); //Leggo il file
    char readBuffer[65536]; //Creo il buffer dove ci metterò la stream
    FileReadStream is(fp, readBuffer, sizeof(readBuffer)); //Metto tutto in un FileReadStream

    Document d, d2;
    d.ParseStream(is); //Parso il buffer di prima
    assert(d.IsArray()); //Controllo che sia un array
    fclose(fp);
    d2.SetObject();

    Value data(kObjectType);
    Value value1; //Username
    Value value2; //Password
    Value value3; //BestScore(0)

    value1.SetString(Username.c_str(), d2.GetAllocator()); //Metto la stringa con l'username in "value1" con l'allocator di d2
    value2.SetString(Password.c_str(), d2.GetAllocator()); //Metto la stringa con la password in "value2" con l'allocator di d2
    value3.SetInt(0); //Metto la stringa con il best score(0) con l'allocator di d2

    data.AddMember("Username", value1, d2.GetAllocator()); //Aggiungo l'username all'oggetto "data"
    data.AddMember("Password", value2, d2.GetAllocator()); //Aggiungo la password all'oggetto "data"
    data.AddMember("BestScore", value3, d2.GetAllocator()); //Aggiungo il BestScore all'oggetto "data"

    d.PushBack(data, d2.GetAllocator()); //Aggiungo l'oggetto "data" al documento "d"


    FILE* outfile = fopen("./Users/Users.json", "wb"); //Scrivo il file
    char writeBuffer[65536]; //Creo il buffer dove ci metterò la stream
    FileWriteStream os(outfile, writeBuffer, sizeof(writeBuffer)); //Metto tutto in un FileWriteStream

    Writer<FileWriteStream> writer(os); //Uso un writer per parsarlo nel documento
    d.Accept (writer); //Metto il buffer parsato nel documento
    fclose(outfile);
}

bool CarattereSpec(char carattere)
{
    if ((carattere >= 65 && carattere <= 90) || (carattere >= 97 && carattere <= 122)) //Controllo che non sia una lettera dell'alfabeto
        return false;

    else if (carattere >= 48 && carattere <= 57) //Controllo che non sia un numero
        return false;
  
    else //Se non è una lettera o un numero allora è un carattere speciale
        return true;
}

bool ControlloPassword(std::string Pass, std::string ConfPass)
{
    bool Cap = false, Num = false, Char = false;

    if(Pass != ConfPass) //Controllo che le password siano uguali
    {
        EqError = true;
        return false;
    }
    else EqError = false;

    if(Pass.length() <= 8)
    {
        LenghtError = true; //Controllo che la password sia più lunga di 8 caratteri
        return false;
    }
    else LenghtError = false;

    for(int i = 0; i < Pass.length(); i++)
    {
        if(isupper(Pass.at(i))) Cap = true; //Controllo che nella password ci sia almeno una maiuscola

        if(isdigit(Pass.at(i))) Num = true; //Controllo che nella password ci sia almeno un numero

        if(CarattereSpec(Pass.at(i))) Char = true; //Controllo che nella password ci sia almeno un carattere speciale

        if((Cap == true && Num == true) && Char == true) break;
    }

    if( Cap == false )
    {
        CapError = true;
        return false;
    }
    else CapError = false;
    

    if( Num == false )
    {
        NumError = true;
        return false;
    }
    else NumError = false;

    if( Char == false )
    {
        SpecCharError = true;
        return false;
    }
    else SpecCharError = false;

    return true;
}

void SignUpWindow(sf::Font arial, sf::Font ThaleahFat);
void startWindow(sf::Font arial, sf::Font ThaleahFat);

//Aggiungere un bottone per Confermare e uno per Ritornare alla schermata dove puoi scegliere se Accedere o Registrarti

void signUpWindow(sf::Font arial, sf::Font ThaleahFat) //Finestra Accedi
{
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.create(sf::VideoMode(WIDTH, HEIGH), "Sing in Or Sing up", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    sf::Text Title("Sign Up!", ThaleahFat);
    Title.setCharacterSize(100);
    Title.setFillColor(sf::Color::White);
    Title.setPosition(sf::Vector2f(WIDTH / 2.f - Title.getLocalBounds().width / 2, 50));



 
    sf::Text UsernameText("Username:", ThaleahFat);
    UsernameText.setCharacterSize(30);
    UsernameText.setFillColor(sf::Color::White);
    UsernameText.setPosition( { 75, 185 } );
    
    sf::Color UsernameBtnColor(128, 128, 128);
    Button btnUsername("", { 750, 65 }, 20, UsernameBtnColor, sf::Color::Black);
    btnUsername.setPosition( { 75, 225 } );
    
    Textbox UsernameTextBox(15, sf::Color::White, false);
    UsernameTextBox.setFont(arial);
    UsernameTextBox.setPosition( {100, 250} );
    UsernameTextBox.setLimit(true, 85);




    sf::Text PasswordText("Password:", ThaleahFat);
    PasswordText.setCharacterSize(30);
    PasswordText.setFillColor(sf::Color::White);
    PasswordText.setPosition( { 75, 350 } );
    
    sf::Color PasswordBtnColor(128, 128, 128);
    Button btnPassword("", { 750, 65 }, 20, PasswordBtnColor, sf::Color::Black);
    btnPassword.setPosition( { 75, 390 } );
    
    Textbox PasswordTextBox(15, sf::Color::White, true);
    PasswordTextBox.setFont(arial);
    PasswordTextBox.setPosition( {100, 415} );
    PasswordTextBox.setLimit(true, 85);


    Button Accept("Accept", { 200, 50 }, 20, sf::Color::Green, sf::Color::Black);
    Accept.setPosition( { 75, 550 } );
    Accept.setFont(arial);



    Button Return("Return", { 200, 50 }, 20, sf::Color::Green, sf::Color::Black);
    Return.setPosition( { (WIDTH - 75) - 200, 550 } );
    Return.setFont(arial);



    sf::Text UserNotRecognized("User Not Recognized...", ThaleahFat);
    UserNotRecognized.setCharacterSize(30);
    UserNotRecognized.setFillColor(sf::Color::White);
    UserNotRecognized.setPosition( { 75, 475 } );



    bool UserError = false;

    while(window.isOpen())
    {
        sf::Event evnt;

        while(window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                ClosedWindow = true;
                window.close();
                break;
            case sf::Event::TextEntered:
                UsernameTextBox.typedOn(evnt);
                PasswordTextBox.typedOn(evnt);
                break;
            case sf::Event::MouseMoved:
                if(btnUsername.isMouseOver(window))
                {
                    UsernameTextBox.setSelected(true);
                }
                else 
                {
                    UsernameTextBox.setSelected(false);
                }
                if(btnPassword.isMouseOver(window))
                {
                    PasswordTextBox.setSelected(true);
                }
                else
                {
                    PasswordTextBox.setSelected(false);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if(Accept.isMouseOver(window) && Sign_up(UsernameTextBox.getText(), PasswordTextBox.getText()))
                {
                    Username = UsernameTextBox.getText();
                    Password = PasswordTextBox.getText();
                    
                    window.close();
                }
                else if(Accept.isMouseOver(window) && !(Sign_up(UsernameTextBox.getText(), PasswordTextBox.getText())))
                {
                    UserError = true;
                }
                if(Return.isMouseOver(window))
                {
                    window.close();
                    startWindow(arial, ThaleahFat);
                }
            }
            window.clear();
            btnUsername.drawTo(window);
            window.draw(UsernameText);
            UsernameTextBox.drawTo(window);
            btnPassword.drawTo(window);
            window.draw(PasswordText);
            PasswordTextBox.drawTo(window);
            window.draw(Title);
            Accept.drawTo(window);
            Return.drawTo(window);
            if(UserError) window.draw(UserNotRecognized);
            window.display();
        }
    }
}

void signInWindow(sf::Font arial, sf::Font ThaleahFat) //Finestra Registrati
{
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.create(sf::VideoMode(WIDTH, HEIGH), "Sing in Or Sing up", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    sf::Text Title("Sign In!", ThaleahFat);
    Title.setCharacterSize(100);
    Title.setFillColor(sf::Color::White);
    Title.setPosition(sf::Vector2f(WIDTH / 2.f - Title.getLocalBounds().width / 2, 50));



 
    sf::Text UsernameText("Username:", ThaleahFat);
    UsernameText.setCharacterSize(30);
    UsernameText.setFillColor(sf::Color::White);
    UsernameText.setPosition( { 75, 185 } );
    
    sf::Color UsernameBtnColor(128, 128, 128);
    Button btnUsername("", { 750, 65 }, 20, UsernameBtnColor, sf::Color::Black);
    btnUsername.setPosition( { 75, 225 } );
    
    Textbox UsernameTextBox(15, sf::Color::White, false);
    UsernameTextBox.setFont(arial);
    UsernameTextBox.setPosition( {100, 250} );
    UsernameTextBox.setLimit(true, 85);




    sf::Text PasswordText("Password:", ThaleahFat);
    PasswordText.setCharacterSize(30);
    PasswordText.setFillColor(sf::Color::White);
    PasswordText.setPosition( { 75, 350 } );
    
    sf::Color PasswordBtnColor(128, 128, 128);
    Button btnPassword("", { 750, 65 }, 20, PasswordBtnColor, sf::Color::Black);
    btnPassword.setPosition( { 75, 390 } );
    
    Textbox PasswordTextBox(15, sf::Color::White, true);
    PasswordTextBox.setFont(arial);
    PasswordTextBox.setPosition( {100, 415} );
    PasswordTextBox.setLimit(true, 85);



    sf::Text ConfPasswordText("Confirm Password:", ThaleahFat);
    ConfPasswordText.setCharacterSize(30);
    ConfPasswordText.setFillColor(sf::Color::White);
    ConfPasswordText.setPosition( { 75, 515 } );
    
    sf::Color ConfPasswordBtnColor(128, 128, 128);
    Button ConfbtnPassword("", { 750, 65 }, 20, ConfPasswordBtnColor, sf::Color::Black);
    ConfbtnPassword.setPosition( { 75, 555 } );
    
    Textbox ConfPasswordTextBox(15, sf::Color::White, true);
    ConfPasswordTextBox.setFont(arial);
    ConfPasswordTextBox.setPosition( {100, 580} );
    ConfPasswordTextBox.setLimit(true, 85);


    Button Accept("Accept", { 200, 50 }, 20, sf::Color::Green, sf::Color::Black);
    Accept.setPosition( { 75, 640 } );
    Accept.setFont(arial);



    Button Return("Return", { 200, 50 }, 20, sf::Color::Green, sf::Color::Black);
    Return.setPosition( { (WIDTH - 75) - 200, 640 } );
    Return.setFont(arial);



    sf::Text EqErrorText("Passwords are different...", ThaleahFat);
    EqErrorText.setCharacterSize(30);
    EqErrorText.setFillColor(sf::Color::White);
    EqErrorText.setPosition( { 75, ERRORS_SIGN_IN_Y_DEF } );



    sf::Text LenghtErrorText("Minimum password length: 8 characters...", ThaleahFat);
    LenghtErrorText.setCharacterSize(30);
    LenghtErrorText.setFillColor(sf::Color::White);
    LenghtErrorText.setPosition( { 75, ERRORS_SIGN_IN_Y_DEF + ( EqErrorText.getLocalBounds().height + ERRORS_SIGN_IN_Y_OFF ) } );



    sf::Text SpecCharErrorText("The password must have at least one special character...", ThaleahFat);
    SpecCharErrorText.setCharacterSize(30);
    SpecCharErrorText.setFillColor(sf::Color::White);
    SpecCharErrorText.setPosition( { 75, ERRORS_SIGN_IN_Y_DEF + ( ( EqErrorText.getLocalBounds().height + ERRORS_SIGN_IN_Y_OFF ) + ( LenghtErrorText.getLocalBounds().height + ERRORS_SIGN_IN_Y_OFF ) ) } );



    sf::Text NumErrorText("The password must have at least one number...", ThaleahFat);
    NumErrorText.setCharacterSize(30);
    NumErrorText.setFillColor(sf::Color::White);
    NumErrorText.setPosition( { 75, ERRORS_SIGN_IN_Y_DEF + ( ( EqErrorText.getLocalBounds().height + ERRORS_SIGN_IN_Y_OFF ) + ( LenghtErrorText.getLocalBounds().height + ERRORS_SIGN_IN_Y_OFF ) + (SpecCharErrorText.getLocalBounds().height + ERRORS_SIGN_IN_Y_OFF ) ) } );



    sf::Text CapErrorText("The password must have at least one capital letter...", ThaleahFat);
    CapErrorText.setCharacterSize(30);
    CapErrorText.setFillColor(sf::Color::White);
    CapErrorText.setPosition( { 75, ERRORS_SIGN_IN_Y_DEF + ( ( EqErrorText.getLocalBounds().height + ERRORS_SIGN_IN_Y_OFF ) + ( LenghtErrorText.getLocalBounds().height + ERRORS_SIGN_IN_Y_OFF ) + ( SpecCharErrorText.getLocalBounds().height + ERRORS_SIGN_IN_Y_OFF ) + ( NumErrorText.getLocalBounds().height + ERRORS_SIGN_IN_Y_OFF ) ) } );

    while(window.isOpen())
    {
        sf::Event evnt;

        while(window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                ClosedWindow = true;
                window.close();
                break;
            case sf::Event::TextEntered:
                UsernameTextBox.typedOn(evnt);
                PasswordTextBox.typedOn(evnt);
                ConfPasswordTextBox.typedOn(evnt);
                break;
            case sf::Event::MouseMoved:
                if(btnUsername.isMouseOver(window))
                {
                    UsernameTextBox.setSelected(true);
                }
                else
                {
                    UsernameTextBox.setSelected(false);
                }

                if(btnPassword.isMouseOver(window))
                {
                    PasswordTextBox.setSelected(true);
                }
                else
                {
                    PasswordTextBox.setSelected(false);
                }

                if(ConfbtnPassword.isMouseOver(window))
                {
                    ConfPasswordTextBox.setSelected(true);
                }
                else
                {
                    ConfPasswordTextBox.setSelected(false);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if(Accept.isMouseOver(window) && ControlloPassword(PasswordTextBox.getText(), ConfPasswordTextBox.getText()))
                {
                    Sign_in(UsernameTextBox.getText(), PasswordTextBox.getText());
                    window.close();
                }
                
                if(Return.isMouseOver(window))
                {
                    window.close();
                    startWindow(arial, ThaleahFat);
                }
            }
            window.clear();
            btnUsername.drawTo(window);
            window.draw(UsernameText);
            UsernameTextBox.drawTo(window);
            btnPassword.drawTo(window);
            window.draw(PasswordText);
            PasswordTextBox.drawTo(window);
            window.draw(Title);
            ConfbtnPassword.drawTo(window);
            window.draw(ConfPasswordText);
            ConfPasswordTextBox.drawTo(window);
            Accept.drawTo(window);
            Return.drawTo(window);
            //Possible Errors
            if(EqError) window.draw(EqErrorText);
            if(LenghtError) window.draw(LenghtErrorText);
            if(SpecCharError) window.draw(SpecCharErrorText);
            if(NumError) window.draw(NumErrorText);
            if(CapError) window.draw(CapErrorText);
            window.display();
        }
    }
}

void startWindow(sf::Font arial, sf::Font ThaleahFat) //Finestra di inizio
{
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.create(sf::VideoMode(WIDTH, HEIGH), "Sing in Or Sing up", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    sf::Text Title("Welcome!", ThaleahFat);
    Title.setCharacterSize(100);
    Title.setFillColor(sf::Color::White);
    Title.setPosition(sf::Vector2f(WIDTH / 2.f - Title.getLocalBounds().width / 2, 50));

    Button btnSignUp("Sign Up", {200, 50}, 20, sf::Color::Green, sf::Color::Black);
    btnSignUp.setPosition( { 100, 300 } );
    btnSignUp.setFont(arial);

    Button btnSignIn("Sign In", {200, 50}, 20, sf::Color::Green, sf::Color::Black);
    btnSignIn.setPosition( { 600, 300} );
    btnSignIn.setFont(arial);

    while(window.isOpen())
    {
        sf::Event evnt;

        while(window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                ClosedWindow = true;
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if(btnSignUp.isMouseOver(window))
                {
                    window.close();
                    signUpWindow(arial, ThaleahFat);
                }
                else if(btnSignIn.isMouseOver(window))
                {
                    window.close();
                    signInWindow(arial, ThaleahFat);
                }
                
                break;
            }
            window.clear();
            btnSignUp.drawTo(window);
            btnSignIn.drawTo(window);
            window.draw(Title);
            window.display();
        }
    }
}