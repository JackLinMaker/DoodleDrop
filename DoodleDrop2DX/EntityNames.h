//
//  EntityNames.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-24.
//
//

#ifndef DoodleDrop2DX_EntityNames_h
#define DoodleDrop2DX_EntityNames_h

enum
{
    ent_Allien,
    
    ent_Spider
};

inline std::string GetNameOfEntity(int n)
{
    switch (n) {
        case ent_Allien:
            return "Allien";
            break;
        case ent_Spider:
            return "Spider";
            break;
            
        default:
            return "UNKNOWN";
            break;
    }
}

#endif
