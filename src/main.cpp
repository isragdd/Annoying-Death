#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    void onMoreGames(CCObject*) {
        FLAlertLayer::create("Test!", "I LOVE CATSS!", "Alr")->show();
    }
};

class $modify(MyPlayLayer, PlayLayer) {
    void showNewBest(bool newReward, int orbs, int diamonds, bool demonKey, bool noRetry, bool noTitle) {
        PlayLayer::showNewBest(newReward, orbs, diamonds, demonKey, noRetry, noTitle);

        auto children = this->getChildren();
        if (!children) return;

        for (int i = 0; i < children->count(); i++) {
            auto child = static_cast<CCNode*>(children->objectAtIndex(i));
            if (!child) continue;

            auto grandchildren = child->getChildren();
            if (!grandchildren) continue;
            if (grandchildren->count() < 2) continue;

            auto firstChild = static_cast<CCNode*>(grandchildren->objectAtIndex(0));
            auto secondChild = static_cast<CCNode*>(grandchildren->objectAtIndex(1));

            auto label = dynamic_cast<CCLabelBMFont*>(firstChild);
            auto percentage = dynamic_cast<CCLabelBMFont*>(secondChild);

            if (label && percentage) {
                const char* customMessages[] = { 
                    "Tienes 14? prende cam>:)",
                    "skill issue",
                    "ts pmo icl",
                    "ez",
                    "L",
                    "zzz",
                    "seriously? js here??",
                    "you can't do better, can you?",
                    "you had to pause and somehow hide the pause menu js to read this, that its literally js nothing but nosense made by the dev just to piss you off and make you waste time of your life, but here you are still reading this? just stop vro wth",
                    "shameful",
                    "ur trash gng",
                    "are we deadass rn",
                    "vro js quit atp",
                    "i would say ggs, but it was NOT good",
                    "delete the game rn",
                    "retire bro",
                    "nah this ain’t you, rightt?",
                    "lost to air",
                    "get help",
                    "ratio",
                    "bro thinks he’s him",
                    "sit down lil bro",
                    "this ain’t a highlight",
                    "rent free",
                    "npc ahh",
                    "get tf outta my game vro",
                    "put the controller down",
                    "im embarrassed for u",
                    "bro fighting demons and losing",
                    "not even close",
                    "yawn.",
                    "uh...",
                    "yt tutorials are free",
                    "who even let u play",
                    "u ain’t tuff",
                    "just stop trying",
                    "dont ever try that again",
                    "take notes next time",
                    "washed",
                    "missed every jump",
                    "outplayed by nothing",
                    "sign out g",
                    "controller unplugged?",
                    "bro lagging in real life",
                    "what was it, did your monitor lag?",
                    "you call that gameplay?",
                    "just uninstall",
                    "not built for this"
                };

                int arraySize = sizeof(customMessages) / sizeof(customMessages[0]);
                const char* randomMessage = customMessages[rand() % arraySize];

                label->setString(randomMessage);
                percentage->setString("0%");
                return;
            }
        }
    }
};