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
    unsigned Anzeige_get() noexcept;
    void Anzeige_set(unsigned) noexcept;
    /* flatenned list "Thema2"             */
    char Thema_1[41];
    unsigned Anzeige_2_get() noexcept;
    void Anzeige_2_set(unsigned) noexcept;
    /* flatenned list "Thema3"             */
    char Thema_3[41];
    unsigned Anzeige_4_get() noexcept;
    void Anzeige_4_set(unsigned) noexcept;
    /* flatenned list "Thema4"             */
    char Thema_5[41];
    unsigned Anzeige_6_get() noexcept;
    void Anzeige_6_set(unsigned) noexcept;
    /* flatenned list "Thema5"             */
    char Thema_7[41];
    unsigned Anzeige_8_get() noexcept;
    void Anzeige_8_set(unsigned) noexcept;
    /* flatenned list "Thema6"             */
    char Thema_9[41];
    unsigned Anzeige_10_get() noexcept;
    void Anzeige_10_set(unsigned) noexcept;
    unsigned Fehler_get() noexcept;
    void Fehler_set(unsigned) noexcept;
    unsigned Update_get() noexcept;
    void Update_set(unsigned) noexcept;
    
    /**************************************************************************/
    
    const cojson::details::value& json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ValueObject<
                MemberValue<__config::Thema1, ValueArray<
                    ValueObject<
                        MemberValue<__config::Thema, ValueString<std::extent<decltype(Thema),0>::value, Thema>>,
                        MemberValue<__config::Anzeige, ValueGetterSetter<std::result_of<decltype(Anzeige_get)&()>::type, &Anzeige_get, &Anzeige_set>>
                    >
                >>,
                MemberValue<__config::Thema2, ValueArray<
                    ValueObject<
                        MemberValue<__config::Thema, ValueString<std::extent<decltype(Thema_1),0>::value, Thema_1>>,
                        MemberValue<__config::Anzeige, ValueGetterSetter<std::result_of<decltype(Anzeige_2_get)&()>::type, &Anzeige_2_get, &Anzeige_2_set>>
                    >
                >>,
                MemberValue<__config::Thema3, ValueArray<
                    ValueObject<
                        MemberValue<__config::Thema, ValueString<std::extent<decltype(Thema_3),0>::value, Thema_3>>,
                        MemberValue<__config::Anzeige, ValueGetterSetter<std::result_of<decltype(Anzeige_4_get)&()>::type, &Anzeige_4_get, &Anzeige_4_set>>
                    >
                >>,
                MemberValue<__config::Thema4, ValueArray<
                    ValueObject<
                        MemberValue<__config::Thema, ValueString<std::extent<decltype(Thema_5),0>::value, Thema_5>>,
                        MemberValue<__config::Anzeige, ValueGetterSetter<std::result_of<decltype(Anzeige_6_get)&()>::type, &Anzeige_6_get, &Anzeige_6_set>>
                    >
                >>,
                MemberValue<__config::Thema5, ValueArray<
                    ValueObject<
                        MemberValue<__config::Thema, ValueString<std::extent<decltype(Thema_7),0>::value, Thema_7>>,
                        MemberValue<__config::Anzeige, ValueGetterSetter<std::result_of<decltype(Anzeige_8_get)&()>::type, &Anzeige_8_get, &Anzeige_8_set>>
                    >
                >>,
                MemberValue<__config::Thema6, ValueArray<
                    ValueObject<
                        MemberValue<__config::Thema, ValueString<std::extent<decltype(Thema_9),0>::value, Thema_9>>,
                        MemberValue<__config::Anzeige, ValueGetterSetter<std::result_of<decltype(Anzeige_10_get)&()>::type, &Anzeige_10_get, &Anzeige_10_set>>
                    >
                >>,
                MemberValue<__config::Fehler, ValueGetterSetter<std::result_of<decltype(Fehler_get)&()>::type, &Fehler_get, &Fehler_set>>,
                MemberValue<__config::Update, ValueGetterSetter<std::result_of<decltype(Update_get)&()>::type, &Update_get, &Update_set>>
            >();
    }
    
    /**************************************************************************/
    unsigned Anzeige;
    unsigned Anzeige_2;
    unsigned Anzeige_4;
    unsigned Anzeige_6;
    unsigned Anzeige_8;
    unsigned Anzeige_10;
    unsigned Fehler;
    unsigned Update;
    
    unsigned Anzeige_get() noexcept {
        return Anzeige;
    }
    void Anzeige_set(unsigned _Anzeige) noexcept {
        Anzeige = _Anzeige;
    }
    
    unsigned Anzeige_2_get() noexcept {
        return Anzeige_2;
    }
    void Anzeige_2_set(unsigned _Anzeige_2) noexcept {
        Anzeige_2 = _Anzeige_2;
    }
    
    unsigned Anzeige_4_get() noexcept {
        return Anzeige_4;
    }
    void Anzeige_4_set(unsigned _Anzeige_4) noexcept {
        Anzeige_4 = _Anzeige_4;
    }
    
    unsigned Anzeige_6_get() noexcept {
        return Anzeige_6;
    }
    void Anzeige_6_set(unsigned _Anzeige_6) noexcept {
        Anzeige_6 = _Anzeige_6;
    }
    
    unsigned Anzeige_8_get() noexcept {
        return Anzeige_8;
    }
    void Anzeige_8_set(unsigned _Anzeige_8) noexcept {
        Anzeige_8 = _Anzeige_8;
    }
    
    unsigned Anzeige_10_get() noexcept {
        return Anzeige_10;
    }
    void Anzeige_10_set(unsigned _Anzeige_10) noexcept {
        Anzeige_10 = _Anzeige_10;
    }
    
    unsigned Fehler_get() noexcept {
        return Fehler;
    }
    void Fehler_set(unsigned _Fehler) noexcept {
        Fehler = _Fehler;
    }
    
    unsigned Update_get() noexcept {
        return Update;
    }
    void Update_set(unsigned _Update) noexcept {
        Update = _Update;
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