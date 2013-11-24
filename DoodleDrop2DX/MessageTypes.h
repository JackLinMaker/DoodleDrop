//
//  MessageTypes.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-24.
//
//

#ifndef DoodleDrop2DX_MessageTypes_h
#define DoodleDrop2DX_MessageTypes_h

#include <string>

enum message_type
{
    Msg_CollideWithSpider,
    Msg_ResetSpiders,
};

inline std::string MsgToStr(int msg)
{
    switch (msg) {
        case Msg_CollideWithSpider:
            return "CollideWithSpider";
            break;
        case Msg_ResetSpiders:
            return "ResetSpiders";
            break;
            
        default:
            return "Not recognized!";
    }
}
#endif
