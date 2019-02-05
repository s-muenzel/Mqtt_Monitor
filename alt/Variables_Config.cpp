/*
 * This file is generated with COJSON Code Generator
 * You can redistribute it and/or modify it under the terms of the
 * GNU General Public License v2
 *
 * Build your application with cojson library
 *
 * ¹ Note: You may install cojson library in your Arduino Studio using this zip:
 *         http://hutorny.in.ua/codegen/cojson.zip
 */
#include <cojson.h>
#include <Arduino.h>
namespace Config {
    /* Name collision : "Thema"
       Use --members or --methods instead of --variables or --fucntions */
    /* Name collision : "Anzeige" */
    /* Name collision : "Thema" */
    /* Name collision : "Anzeige" */
    /* Name collision : "Thema" */
    /* Name collision : "Anzeige" */
    /* Name collision : "Thema" */
    /* Name collision : "Anzeige" */
    /* Name collision : "Thema" */
    /* Name collision : "Anzeige" */
    namespace __config {#    ifdef __AVR__#        define CSTRING_NAME(a,b) inline cojson::cstring a() noexcept {\
                static const char l[] __attribute__((progmem))= b;\
                return cojson::cstring(l);\
            }#    else#        define CSTRING_NAME(a,b) inline cojson::cstring a() noexcept {\
                    return b; }#    endif
        CSTRING_NAME(Thema1,"Thema1") 
        CSTRING_NAME(Thema,"Thema") 
        CSTRING_NAME(Anzeige,"Anzeige") 
        CSTRING_NAME(Thema2,"Thema2") 
        CSTRING_NAME(Thema3,"Thema3") 
        CSTRING_NAME(Thema4,"Thema4") 
        CSTRING_NAME(Thema5,"Thema5") 
        CSTRING_NAME(Thema6,"Thema6") 
        CSTRING_NAME(Fehler,"Fehler") 
        CSTRING_NAME(Update,"Update") #    undef CSTRING_NAME
    }
    /* flatenned list "Thema1"             */
    char Thema[41];
    unsigned Anzeige;
    /* flatenned list "Thema2"             */
    char Thema_1[41];
    unsigned Anzeige_2;
    /* flatenned list "Thema3"             */
    char Thema_3[41];
    unsigned Anzeige_4;
    /* flatenned list "Thema4"             */
    char Thema_5[41];
    unsigned Anzeige_6;
    /* flatenned list "Thema5"             */
    char Thema_7[41];
    unsigned Anzeige_8;
    /* flatenned list "Thema6"             */
    char Thema_9[41];
    unsigned Anzeige_10;
    unsigned Fehler;
    unsigned Update;
    
    /**************************************************************************/
    
    const cojson::details::value& json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ValueObject<
                MemberValue<__config::Thema1, ValueArray<
                    ValueObject<
                        MemberValue<__config::Thema, ValueString<std::extent<decltype(Thema),0>::value, Thema>>,
                        MemberPointer<__config::Anzeige, decltype(Anzeige), &Anzeige>
                    >>
                >,
                MemberValue<__config::Thema2, ValueArray<
                    ValueObject<
                        MemberValue<__config::Thema, ValueString<std::extent<decltype(Thema_1),0>::value, Thema_1>>,
                        MemberPointer<__config::Anzeige, decltype(Anzeige_2), &Anzeige_2>
                    >>
                >,
                MemberValue<__config::Thema3, ValueArray<
                    ValueObject<
                        MemberValue<__config::Thema, ValueString<std::extent<decltype(Thema_3),0>::value, Thema_3>>,
                        MemberPointer<__config::Anzeige, decltype(Anzeige_4), &Anzeige_4>
                    >>
                >,
                MemberValue<__config::Thema4, ValueArray<
                    ValueObject<
                        MemberValue<__config::Thema, ValueString<std::extent<decltype(Thema_5),0>::value, Thema_5>>,
                        MemberPointer<__config::Anzeige, decltype(Anzeige_6), &Anzeige_6>
                    >>
                >,
                MemberValue<__config::Thema5, ValueArray<
                    ValueObject<
                        MemberValue<__config::Thema, ValueString<std::extent<decltype(Thema_7),0>::value, Thema_7>>,
                        MemberPointer<__config::Anzeige, decltype(Anzeige_8), &Anzeige_8>
                    >>
                >,
                MemberValue<__config::Thema6, ValueArray<
                    ValueObject<
                        MemberValue<__config::Thema, ValueString<std::extent<decltype(Thema_9),0>::value, Thema_9>>,
                        MemberPointer<__config::Anzeige, decltype(Anzeige_10), &Anzeige_10>
                    >>
                >,
                MemberPointer<__config::Fehler, decltype(Fehler), &Fehler>,
                MemberPointer<__config::Update, decltype(Update), &Update>
            >();
    }
    
    /**************************************************************************/
}

/**************************************************************************/

void setup() {
    Serial.begin(9600);
    while (!Serial) {};
}

void loop() {
    cojson::wrapper::iostream<decltype(Serial)> serialio(Serial);
    serialio.echo(true);
    if( Serial.available() ) {
        Config::json().read(serialio);
        Serial.println();
        if( + serialio.error() ) {
            Serial.println("JSON error");
            serialio.clear();
            while( Serial.available() ) Serial.read();
        }
        Config::json().write(serialio);
        Serial.println();
    }
}