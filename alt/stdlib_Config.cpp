/*
 * This file is generated with COJSON Code Generator
 * You can redistribute it and/or modify it under the terms of the
 * GNU General Public License v2
 *
 * Build your application with cojson library
 *
 * ¹ Note: You may install cojson library in your Arduino Studio using this zip:
 *         http://hutorny.in.ua/codegen/cojson.zip
 *
 * ² Note: GCC AVR has no support for C++ stdlib
 */
#include <string>
#include <vector>
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
            std::string Thema;
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
        std::vector<Thema1_1> Thema1;
        
        struct Thema2_2 {
            std::string Thema;
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
        std::vector<Thema2_2> Thema2;
        
        struct Thema3_3 {
            std::string Thema;
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
        std::vector<Thema3_3> Thema3;
        
        struct Thema4_4 {
            std::string Thema;
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
        std::vector<Thema4_4> Thema4;
        
        struct Thema5_5 {
            std::string Thema;
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
        std::vector<Thema5_5> Thema5;
        
        struct Thema6_6 {
            std::string Thema;
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
        std::vector<Thema6_6> Thema6;
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
                PropertyStdVector<myConfig, __config::Thema1, decltype(myConfig::Thema1), &myConfig::Thema1, decltype(myConfig::Thema1)::value_type::json>,
                PropertyStdVector<myConfig, __config::Thema2, decltype(myConfig::Thema2), &myConfig::Thema2, decltype(myConfig::Thema2)::value_type::json>,
                PropertyStdVector<myConfig, __config::Thema3, decltype(myConfig::Thema3), &myConfig::Thema3, decltype(myConfig::Thema3)::value_type::json>,
                PropertyStdVector<myConfig, __config::Thema4, decltype(myConfig::Thema4), &myConfig::Thema4, decltype(myConfig::Thema4)::value_type::json>,
                PropertyStdVector<myConfig, __config::Thema5, decltype(myConfig::Thema5), &myConfig::Thema5, decltype(myConfig::Thema5)::value_type::json>,
                PropertyStdVector<myConfig, __config::Thema6, decltype(myConfig::Thema6), &myConfig::Thema6, decltype(myConfig::Thema6)::value_type::json>,
                PropertyScalarMember<myConfig, __config::Fehler, decltype(myConfig::Fehler), &myConfig::Fehler>,
                PropertyScalarMember<myConfig, __config::Update, decltype(myConfig::Update), &myConfig::Update>
            >();
    }
    
    const cojson::details::clas<myConfig::Thema1_1>& myConfig::Thema1_1::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<Thema1_1,
                PropertyStdString<Thema1_1, __config::Thema, decltype(Thema1_1::Thema), &Thema1_1::Thema>,
                PropertyScalarMember<Thema1_1, __config::Anzeige, decltype(Thema1_1::Anzeige), &Thema1_1::Anzeige>
            >();
    }
    
    const cojson::details::clas<myConfig::Thema2_2>& myConfig::Thema2_2::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<Thema2_2,
                PropertyStdString<Thema2_2, __config::Thema, decltype(Thema2_2::Thema), &Thema2_2::Thema>,
                PropertyScalarMember<Thema2_2, __config::Anzeige, decltype(Thema2_2::Anzeige), &Thema2_2::Anzeige>
            >();
    }
    
    const cojson::details::clas<myConfig::Thema3_3>& myConfig::Thema3_3::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<Thema3_3,
                PropertyStdString<Thema3_3, __config::Thema, decltype(Thema3_3::Thema), &Thema3_3::Thema>,
                PropertyScalarMember<Thema3_3, __config::Anzeige, decltype(Thema3_3::Anzeige), &Thema3_3::Anzeige>
            >();
    }
    
    const cojson::details::clas<myConfig::Thema4_4>& myConfig::Thema4_4::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<Thema4_4,
                PropertyStdString<Thema4_4, __config::Thema, decltype(Thema4_4::Thema), &Thema4_4::Thema>,
                PropertyScalarMember<Thema4_4, __config::Anzeige, decltype(Thema4_4::Anzeige), &Thema4_4::Anzeige>
            >();
    }
    
    const cojson::details::clas<myConfig::Thema5_5>& myConfig::Thema5_5::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<Thema5_5,
                PropertyStdString<Thema5_5, __config::Thema, decltype(Thema5_5::Thema), &Thema5_5::Thema>,
                PropertyScalarMember<Thema5_5, __config::Anzeige, decltype(Thema5_5::Anzeige), &Thema5_5::Anzeige>
            >();
    }
    
    const cojson::details::clas<myConfig::Thema6_6>& myConfig::Thema6_6::json() noexcept {
        using namespace cojson;
        using namespace cojson::details;
        return 
            ObjectClass<Thema6_6,
                PropertyStdString<Thema6_6, __config::Thema, decltype(Thema6_6::Thema), &Thema6_6::Thema>,
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