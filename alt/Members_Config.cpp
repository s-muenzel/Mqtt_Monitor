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
    
    struct myConfig {
        
        struct Thema1_1 {
            char Thema[41];
            unsigned Anzeige;
        public:
            static const cojson::details::clas<Thema1_1>& json() noexcept;
            inline bool json(cojson::details::lexer& in) noexcept {
                return json().read(*this, in);
            }
            inline bool json(cojson::details::ostream& out) const noexcept {
                return json().write(*this, out);
            }
        } ;
        Thema1_1 Thema1[1];
        
        struct Thema2_2 {
            char Thema[41];
            unsigned Anzeige;
        public:
            static const cojson::details::clas<Thema2_2>& json() noexcept;
            inline bool json(cojson::details::lexer& in) noexcept {
                return json().read(*this, in);
            }
            inline bool json(cojson::details::ostream& out) const noexcept {
                return json().write(*this, out);
            }
        } ;
        Thema2_2 Thema2[1];
        
        struct Thema3_3 {
            char Thema[41];
            unsigned Anzeige;
        public:
            static const cojson::details::clas<Thema3_3>& json() noexcept;
            inline bool json(cojson::details::lexer& in) noexcept {
                return json().read(*this, in);
            }
            inline bool json(cojson::details::ostream& out) const noexcept {
                return json().write(*this, out);
            }
        } ;
        Thema3_3 Thema3[1];
        
        struct Thema4_4 {
            char Thema[41];
            unsigned Anzeige;
        public:
            static const cojson::details::clas<Thema4_4>& json() noexcept;
            inline bool json(cojson::details::lexer& in) noexcept {
                return json().read(*this, in);
            }
            inline bool json(cojson::details::ostream& out) const noexcept {
                return json().write(*this, out);
            }
        } ;
        Thema4_4 Thema4[1];
        
        struct Thema5_5 {
            char Thema[41];
            unsigned Anzeige;
        public:
            static const cojson::details::clas<Thema5_5>& json() noexcept;
            inline bool json(cojson::details::lexer& in) noexcept {
                return json().read(*this, in);
            }
            inline bool json(cojson::details::ostream& out) const noexcept {
                return json().write(*this, out);
            }
        } ;
        Thema5_5 Thema5[1];
        
        struct Thema6_6 {
            char Thema[41];
            unsigned Anzeige;
        public:
            static const cojson::details::clas<Thema6_6>& json() noexcept;
            inline bool json(cojson::details::lexer& in) noexcept {
                return json().read(*this, in);
            }
            inline bool json(cojson::details::ostream& out) const noexcept {
                return json().write(*this, out);
            }
        } ;
        Thema6_6 Thema6[1];
        unsigned Fehler;
        unsigned Update;
    public:
        static const cojson::details::clas<myConfig>& json() noexcept;
        inline bool json(cojson::details::lexer& in) noexcept {
            return json().read(*this, in);
        }
        inline bool json(cojson::details::ostream& out) const noexcept {
            return json().write(*this, out);
        }
    } myconfig;
    
    /**************************************************************************/
    
    const cojson::details::clas<myConfig>& myConfig::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<myConfig,
                PropertyArrayOfObjects<myConfig, __config::Thema1,
                    std::remove_all_extents<decltype(myConfig::Thema1)>::type,
                    std::extent<decltype(myConfig::Thema1),0>::value,
                    &myConfig::Thema1,
                    std::remove_all_extents<decltype(myConfig::Thema1)>::type::json>,
                PropertyArrayOfObjects<myConfig, __config::Thema2,
                    std::remove_all_extents<decltype(myConfig::Thema2)>::type,
                    std::extent<decltype(myConfig::Thema2),0>::value,
                    &myConfig::Thema2,
                    std::remove_all_extents<decltype(myConfig::Thema2)>::type::json>,
                PropertyArrayOfObjects<myConfig, __config::Thema3,
                    std::remove_all_extents<decltype(myConfig::Thema3)>::type,
                    std::extent<decltype(myConfig::Thema3),0>::value,
                    &myConfig::Thema3,
                    std::remove_all_extents<decltype(myConfig::Thema3)>::type::json>,
                PropertyArrayOfObjects<myConfig, __config::Thema4,
                    std::remove_all_extents<decltype(myConfig::Thema4)>::type,
                    std::extent<decltype(myConfig::Thema4),0>::value,
                    &myConfig::Thema4,
                    std::remove_all_extents<decltype(myConfig::Thema4)>::type::json>,
                PropertyArrayOfObjects<myConfig, __config::Thema5,
                    std::remove_all_extents<decltype(myConfig::Thema5)>::type,
                    std::extent<decltype(myConfig::Thema5),0>::value,
                    &myConfig::Thema5,
                    std::remove_all_extents<decltype(myConfig::Thema5)>::type::json>,
                PropertyArrayOfObjects<myConfig, __config::Thema6,
                    std::remove_all_extents<decltype(myConfig::Thema6)>::type,
                    std::extent<decltype(myConfig::Thema6),0>::value,
                    &myConfig::Thema6,
                    std::remove_all_extents<decltype(myConfig::Thema6)>::type::json>,
                PropertyScalarMember<myConfig, __config::Fehler, decltype(myConfig::Fehler), &myConfig::Fehler>,
                PropertyScalarMember<myConfig, __config::Update, decltype(myConfig::Update), &myConfig::Update>
            >();
    }
    
    const cojson::details::clas<myConfig::Thema1_1>& myConfig::Thema1_1::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<Thema1_1,
                PropertyString<Thema1_1, __config::Thema, std::extent<decltype(Thema1_1::Thema),0>::value, &Thema1_1::Thema>,
                PropertyScalarMember<Thema1_1, __config::Anzeige, decltype(Thema1_1::Anzeige), &Thema1_1::Anzeige>
            >();
    }
    
    const cojson::details::clas<myConfig::Thema2_2>& myConfig::Thema2_2::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<Thema2_2,
                PropertyString<Thema2_2, __config::Thema, std::extent<decltype(Thema2_2::Thema),0>::value, &Thema2_2::Thema>,
                PropertyScalarMember<Thema2_2, __config::Anzeige, decltype(Thema2_2::Anzeige), &Thema2_2::Anzeige>
            >();
    }
    
    const cojson::details::clas<myConfig::Thema3_3>& myConfig::Thema3_3::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<Thema3_3,
                PropertyString<Thema3_3, __config::Thema, std::extent<decltype(Thema3_3::Thema),0>::value, &Thema3_3::Thema>,
                PropertyScalarMember<Thema3_3, __config::Anzeige, decltype(Thema3_3::Anzeige), &Thema3_3::Anzeige>
            >();
    }
    
    const cojson::details::clas<myConfig::Thema4_4>& myConfig::Thema4_4::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<Thema4_4,
                PropertyString<Thema4_4, __config::Thema, std::extent<decltype(Thema4_4::Thema),0>::value, &Thema4_4::Thema>,
                PropertyScalarMember<Thema4_4, __config::Anzeige, decltype(Thema4_4::Anzeige), &Thema4_4::Anzeige>
            >();
    }
    
    const cojson::details::clas<myConfig::Thema5_5>& myConfig::Thema5_5::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<Thema5_5,
                PropertyString<Thema5_5, __config::Thema, std::extent<decltype(Thema5_5::Thema),0>::value, &Thema5_5::Thema>,
                PropertyScalarMember<Thema5_5, __config::Anzeige, decltype(Thema5_5::Anzeige), &Thema5_5::Anzeige>
            >();
    }
    
    const cojson::details::clas<myConfig::Thema6_6>& myConfig::Thema6_6::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<Thema6_6,
                PropertyString<Thema6_6, __config::Thema, std::extent<decltype(Thema6_6::Thema),0>::value, &Thema6_6::Thema>,
                PropertyScalarMember<Thema6_6, __config::Anzeige, decltype(Thema6_6::Anzeige), &Thema6_6::Anzeige>
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
        Config::myconfig.json(serialio.in());
        Serial.println();
        if( + serialio.error() ) {
            Serial.println("JSON error");
            serialio.clear();
            while( Serial.available() ) Serial.read();
        }
        Config::myconfig.json(serialio.out());
        Serial.println();
    }
}