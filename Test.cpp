/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Ohad Maday>
 * 
 * Date: 2020-03
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy bringer pulse boring poring";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find(text, "pringer") == string("bringer"));
    CHECK(find(text, "bringer") == string("pringer"));
    CHECK(find(text, "pulse") == string("bulse"));
    CHECK(find(text, "bulse") == string("pulse"));
    CHECK(find(text, "boring") == string("poring"));
    CHECK(find(text, "poring") == string("boring"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of space bar") {
    string text = " Happi xxx yyy";
    CHECK(find(text, " happi ") == string("Happi"));
    CHECK(find(text, "Ha ppi") == string("Happi"));
    CHECK(find(text, "HAP PI") == string("Happi"));
    CHECK(find(text, "HaPp I") == string("Happi"));
    /* Add more checks here */
}

TEST_CASE("Two or more same words") {
    string text = " Happi haffi haffi yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Haffi") == string("Haffi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
}
TEST_CASE("REALLY LONG WORDS") {
    string text = "HappiHappiHappiHappiHappiHappd HELLOYOUTUBEBEST PEWDIEPIE yyyyyyyyyyyyyyyyyy";
    CHECK(find(text, "HappiHappiHappiHappiHappiHappd") == string("HapPiHaPpiHappiHappiHappiHappd"));
    CHECK(find(text, "helloyoutubebest") == string("helloyoutubebesT"));
    CHECK(find(text, "PEWtIEbIE") == string("PEWDIEPIE"));
    CHECK(find(text, "yyyyyyyyyyyyyyyyyi") == string("yyyyyyyyyyyyyyyyyy"));
    /* Add more checks here */
}
TEST_CASE("spacebar search test") {
    string text = "HappiH appiHappiHappiH appiHa ppd HELLOYOUTUB EBEST PEWD IEPIE yyyyyy ";
    CHECK(find(text, "e best") == string("ebest"));
    /* Add more checks here */
}
TEST_CASE("spacebar search test for short words") {
    string text = "HappiH hello world";
    CHECK(find(text, "hell o") == string("hello"));
    CHECK(find(text, "wo rld") == string("world"));
    /* Add more checks here */
}
TEST_CASE("c or k or q") {
    string text = "corn born queen okay kkie";
    CHECK(find(text, "corn") == string("korn"));
    CHECK(find(text, "kueen") == string("queen"));
    CHECK(find(text, "queen") == string("bueen"));
    CHECK(find(text, "qorn") == string("born"));
    CHECK(find(text, "ocay") == string("okay"));
    CHECK(find(text, "qqie") == string("kkie"));
    /* Add more checks here */
}
TEST_CASE("i or y replacement") {
    string text = "yyellow eyllow ireland russia yardat";
    CHECK(find(text, "iiellow") == string("yyellow"));
    CHECK(find(text, "eillow") == string("eyllow"));
    CHECK(find(text, "queen") == string("bueen"));
    CHECK(find(text, "qorn") == string("born"));
    CHECK(find(text, "ocay") == string("okay"));
    CHECK(find(text, "qqie") == string("kkie"));
    /* Add more checks here */
}
TEST_CASE("j or g replacement") {
    string text = "bjorn ironside ragnar gombajumba";
    CHECK(find(text, "bgorn") == string("bjorn"));
    CHECK(find(text, "bjorn") == string("bgorn"));
    CHECK(find(text, "rajnar") == string("ragnar"));
    CHECK(find(text, "ragnar") == string("rajnar"));
    CHECK(find(text, "jombagumba") == string("gombajumba"));
    CHECK(find(text, "GombaJumba") == string("gombajumba"));
    /* Add more checks here */
}
TEST_CASE("s or z replacement") {
    string text = "sugar zoro zero zugar szero";
    CHECK(find(text, "zugar") == string("sugar"));
    CHECK(find(text, "sugar") == string("zugar"));
    CHECK(find(text, "soro") == string("zoro"));
    CHECK(find(text, "zoro") == string("soro"));
    CHECK(find(text, "zsero") == string("szero"));
    CHECK(find(text, "szero") == string("zsero"));
    /* Add more checks here */
}
TEST_CASE("d or t replacement") {
    string text = "tonight we dine in dell today we dine in corvid";
    CHECK(find(text, "donight") == string("tonight"));
    CHECK(find(text, "tonight") == string("donight"));
    CHECK(find(text, "tine") == string("dine"));
    CHECK(find(text, "dine") == string("tine"));
    CHECK(find(text, "corvit") == string("corvid"));
    CHECK(find(text, "corvid") == string("corvit"));
    /* Add more checks here */
}
TEST_CASE("d or t replacement") {
    string text = "tonight we dine in dell today we dine in corvid";
    CHECK(find(text, "donight") == string("tonight"));
    CHECK(find(text, "tonight") == string("donight"));
    CHECK(find(text, "tine") == string("dine"));
    CHECK(find(text, "dine") == string("tine"));
    CHECK(find(text, "corvit") == string("corvid"));
    CHECK(find(text, "corvid") == string("corvit"));
    /* Add more checks here */
}
TEST_CASE("o or u replacement") {
    string text = "why are you talking to my girlfriend our girlfriend communism";
    CHECK(find(text, "you") == string("yuo"));
    CHECK(find(text, "yuo") == string("you"));
    CHECK(find(text, "yuu") == string("you"));
    CHECK(find(text, "you") == string("yoo"));
    CHECK(find(text, "cummonism") == string("communism"));
    CHECK(find(text, "communism") == string("cummonism"));
    CHECK(find(text, "cummunism") == string("communism"));
    CHECK(find(text, "commonism") == string("communism"));
    /* Add more checks here */
}
TEST_CASE("Shrek: All star pt1") {
	string text = "Somebody once told me the world is gonna roll me I aint the sharpest tool in the shed She was lookin kind of dumb with her finger and her thumb In the shape of an L on her forehead The years start comin and they dont stop comin Fed to the rules and hit the ground runnin Didnt make sense not to live for fun Your brain gets smart but your head gets dumb So much to do so much to see So whats wrong with takin the  backstreets Youll never know if you dont go Youll never shine if you dont glow";
    CHECK(find(text, "zomefodt") == string("somebody"));
    CHECK(find(text, "unke") == string("once"));
    CHECK(find(text, "dolt") == string("told"));
    CHECK(find(text, "wurlt") == string("world"));
    CHECK(find(text, "junna") == string("gonna"));
    CHECK(find(text, "aind") == string("aint"));
    CHECK(find(text, "zharpezd") == string("sharpest"));
    CHECK(find(text, "tuul") == string("tool"));
    CHECK(find(text, "duul") == string("tool"));
    CHECK(find(text, "zhet") == string("shed"));
    CHECK(find(text, "luukinj") == string("looking"));
    CHECK(find(text, "qint") == string("kind"));
    CHECK(find(text, "tomf") == string("dumb"));
    CHECK(find(text, "pynger") == string("finger"));
    CHECK(find(text, "dhomp") == string("thumb"));
    CHECK(find(text, "zhabe") == string("shape"));
    CHECK(find(text, "poreheat") == string("forehead"));
    CHECK(find(text, "yearz") == string("years"));
    CHECK(find(text, "sdard") == string("start"));
    CHECK(find(text, "qumyn") == string("comin"));
    CHECK(find(text, "tund") == string("dont"));
    CHECK(find(text, "rulez") == string("rules"));
    CHECK(find(text, "jruont") == string("ground"));
    CHECK(find(text, "tytnd") == string("Didnt"));
    CHECK(find(text, "mace") == string("make"));
    CHECK(find(text, "zenze") == string("sense"));
    CHECK(find(text, "prayn") == string("brain"));
    CHECK(find(text, "jedz") == string("gets"));
    CHECK(find(text, "daqyn") == string("takin"));
    CHECK(find(text, "pakkzdreedz") == string("backstreets"));
    CHECK(find(text, "yuoll") == string("youll"));
    CHECK(find(text, "zhyne") == string("shine"));
    CHECK(find(text, "jluv") == string("glow"));
    /* Add more checks here */
}
TEST_CASE("All-star pt2 all words combined") {
	string text = "Hey now Youre an allstar Get your game on go play Hey now Youre a rock star Get the show on get paid And all that glitters is gold Only shootin stars break the mold Its a cool place and they say it gets colder Youre bundled up now but wait till you get older But the meteor men beg to differ Judging by the hole in the satellite picture The ice we skate is gettin pretty thin The waters getting warm so you might as well swim My worlds on fire How bout yours Thats the way I like it and Ill never get bored Hey now youre an allstar";
    CHECK(find(text, "jame") == string("game"));
    CHECK(find(text, "flai") == string("play"));
    CHECK(find(text, "yuu") == string("youre"));
    CHECK(find(text, "zdarZ") == string("stars"));
    CHECK(find(text, "gllyderz") == string("glitters"));
    CHECK(find(text, "Jult") == string("gold"));
    CHECK(find(text, "zhuUdyn") == string("shootin"));
    CHECK(find(text, "mult") == string("mold"));
    CHECK(find(text, "freaq") == string("break"));
    CHECK(find(text, "flake") == string("place"));
    CHECK(find(text, "fontlet") == string("bundled"));
    CHECK(find(text, "medeur") == string("meteor"));
    CHECK(find(text, "tibber") == string("differ"));
    CHECK(find(text, "Gotgyng") == string("judging"));
    CHECK(find(text, "Zadelyte") == string("satellite"));
    CHECK(find(text, "biKdore") == string("picture"));
    CHECK(find(text, "Zcade") == string("skate"));
    CHECK(find(text, "jeddYng") == string("getting"));
    CHECK(find(text, "myjhd") == string("might"));
    CHECK(find(text, "wurlDz") == string("worlds"));
    CHECK(find(text, "puret") == string("bored"));
    /* Add more checks here */
}
TEST_CASE("All CAPS") {
	string text = "JOHN LEMON HAMBURGER SPAGET EAT POPE YEAH";
    CHECK(find(text, "joHn") == string("john"));
    CHECK(find(text, "LeMoN") == string("lemon"));
    CHECK(find(text, "HaMbUrGeR") == string("hamburger"));
    CHECK(find(text, "SPAGEt") == string("spaget"));
    CHECK(find(text, "eAt") == string("eat"));
    CHECK(find(text, "poPe") == string("pope"));
    CHECK(find(text, "Yeah") == string("yeah"));

}




