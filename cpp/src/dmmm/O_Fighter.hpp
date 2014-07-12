#ifndef O_FIGHTER
#define O_FIGHTER

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"
#include "T_Fight.hpp"

namespace DMMM {

class O_Fighter{
public:

    O_Fighter() {}

O_Fighter(const I_Fighter& id) 
        : _f_id(id)
        {}


    std::vector<O_Fight> _wins() const
    {
        T_Fight table;
        return table.select(table._winner_id() == _id());   
    }
    std::vector<O_Fight> 
        _wins(const T_Fight::Condition& c) const
    {
        T_Fight table(c);
        return table.select(table._winner_id() == _id());   
    }

    std::vector<O_Fight> _loses() const
    {
        T_Fight table;
        return table.select(table._winner_id() == _id());   
    }
    std::vector<O_Fight> 
        _loses(const T_Fight::Condition& c) const
    {
        T_Fight table(c);
        return table.select(table._winner_id() == _id());   
    }

    const Field<I_Fighter>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Fighter>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _name() const { 
        return _f_name._base; 
    }
    F_String::Base& _name() { 
        _f_name._dirty = true; 
        return _f_name._base; 
    }
    const F_Time::Base& _created_at() const { 
        return _f_created_at._base; 
    }
    F_Time::Base& _created_at() { 
        _f_created_at._dirty = true; 
        return _f_created_at._base; 
    }
    const F_Time::Base& _updated_at() const { 
        return _f_updated_at._base; 
    }
    F_Time::Base& _updated_at() { 
        _f_updated_at._dirty = true; 
        return _f_updated_at._base; 
    }
    const F_Object::Base& _full_data() const { 
        return _f_full_data._base; 
    }
    F_Object::Base& _full_data() { 
        _f_full_data._dirty = true; 
        return _f_full_data._base; 
    }
    const F_String::Base& _url() const { 
        return _f_url._base; 
    }
    F_String::Base& _url() { 
        _f_url._dirty = true; 
        return _f_url._base; 
    }
    const F_Object::Base& _for_delete() const { 
        return _f_for_delete._base; 
    }
    F_Object::Base& _for_delete() { 
        _f_for_delete._dirty = true; 
        return _f_for_delete._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);

        field2Val["updated_at"] = "NOW()";

        if (_f_full_data._dirty)
            field2Val["full_data"] = 
                toSQLString(_f_full_data._base);
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_for_delete._dirty)
            field2Val["for_delete"] = 
                toSQLString(_f_for_delete._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("fighters", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_full_data._dirty = false;
            _f_url._dirty = false;
            _f_for_delete._dirty = false;
            return true;
        }
        else
            return false;
    }

    bool insert(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);

        field2Val["created_at"] = "NOW()";

        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_full_data._dirty)
            field2Val["full_data"] = 
                toSQLString(_f_full_data._base);
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_for_delete._dirty)
            field2Val["for_delete"] = 
                toSQLString(_f_for_delete._base);

        
        if (DBFace::instance()->
                insert("fighters", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_full_data._dirty = false;
            _f_url._dirty = false;
            _f_for_delete._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Fighter> _f_id;
    F_String _f_name;
    F_Time _f_created_at;
    F_Time _f_updated_at;
    F_Object _f_full_data;
    F_String _f_url;
    F_Object _f_for_delete;

    friend class T_Fighter;
};

} //namespace DMMM
#endif //O_FIGHTER
