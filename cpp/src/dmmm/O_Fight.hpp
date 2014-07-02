#ifndef O_FIGHT
#define O_FIGHT

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_Fight{
public:

    O_Fight() {}
    O_Fight(const I_Fighter& parent_id) 
        : _f_winner_id(parent_id)
        {}
    O_Fight(const I_Fighter& parent_id) 
        : _f_loser_id(parent_id)
        {}

O_Fight(const I_Fight& id) 
        : _f_id(id)
        {}


    const Field<I_Fight>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Fight>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_Fixnum::Base& _winner_id() const { 
        return _f_winner_id._base; 
    }
    F_Fixnum::Base& _winner_id() { 
        _f_winner_id._dirty = true; 
        return _f_winner_id._base; 
    }
    const F_Fixnum::Base& _loser_id() const { 
        return _f_loser_id._base; 
    }
    F_Fixnum::Base& _loser_id() { 
        _f_loser_id._dirty = true; 
        return _f_loser_id._base; 
    }
    const F_Time::Base& _date() const { 
        return _f_date._base; 
    }
    F_Time::Base& _date() { 
        _f_date._dirty = true; 
        return _f_date._base; 
    }
    const F_String::Base& _event() const { 
        return _f_event._base; 
    }
    F_String::Base& _event() { 
        _f_event._dirty = true; 
        return _f_event._base; 
    }
    const F_Fixnum::Base& _round() const { 
        return _f_round._base; 
    }
    F_Fixnum::Base& _round() { 
        _f_round._dirty = true; 
        return _f_round._base; 
    }
    const F_Fixnum::Base& _time() const { 
        return _f_time._base; 
    }
    F_Fixnum::Base& _time() { 
        _f_time._dirty = true; 
        return _f_time._base; 
    }
    const F_Object::Base& _exists() const { 
        return _f_exists._base; 
    }
    F_Object::Base& _exists() { 
        _f_exists._dirty = true; 
        return _f_exists._base; 
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
    const F_String::Base& _finish() const { 
        return _f_finish._base; 
    }
    F_String::Base& _finish() { 
        _f_finish._dirty = true; 
        return _f_finish._base; 
    }
    const F_Fixnum::Base& _nonwin() const { 
        return _f_nonwin._base; 
    }
    F_Fixnum::Base& _nonwin() { 
        _f_nonwin._dirty = true; 
        return _f_nonwin._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_winner_id._dirty)
            field2Val["winner_id"] = 
                toSQLString(_f_winner_id._base);
        if (_f_loser_id._dirty)
            field2Val["loser_id"] = 
                toSQLString(_f_loser_id._base);
        if (_f_date._dirty)
            field2Val["date"] = 
                toSQLString(_f_date._base);
        if (_f_event._dirty)
            field2Val["event"] = 
                toSQLString(_f_event._base);
        if (_f_round._dirty)
            field2Val["round"] = 
                toSQLString(_f_round._base);
        if (_f_time._dirty)
            field2Val["time"] = 
                toSQLString(_f_time._base);
        if (_f_exists._dirty)
            field2Val["exists"] = 
                toSQLString(_f_exists._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);

        field2Val["updated_at"] = "NOW()";

        if (_f_finish._dirty)
            field2Val["finish"] = 
                toSQLString(_f_finish._base);
        if (_f_nonwin._dirty)
            field2Val["nonwin"] = 
                toSQLString(_f_nonwin._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("fights", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_winner_id._dirty = false;
            _f_loser_id._dirty = false;
            _f_date._dirty = false;
            _f_event._dirty = false;
            _f_round._dirty = false;
            _f_time._dirty = false;
            _f_exists._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_finish._dirty = false;
            _f_nonwin._dirty = false;
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
        if (_f_winner_id._dirty)
            field2Val["winner_id"] = 
                toSQLString(_f_winner_id._base);
        if (_f_loser_id._dirty)
            field2Val["loser_id"] = 
                toSQLString(_f_loser_id._base);
        if (_f_date._dirty)
            field2Val["date"] = 
                toSQLString(_f_date._base);
        if (_f_event._dirty)
            field2Val["event"] = 
                toSQLString(_f_event._base);
        if (_f_round._dirty)
            field2Val["round"] = 
                toSQLString(_f_round._base);
        if (_f_time._dirty)
            field2Val["time"] = 
                toSQLString(_f_time._base);
        if (_f_exists._dirty)
            field2Val["exists"] = 
                toSQLString(_f_exists._base);

        field2Val["created_at"] = "NOW()";

        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_finish._dirty)
            field2Val["finish"] = 
                toSQLString(_f_finish._base);
        if (_f_nonwin._dirty)
            field2Val["nonwin"] = 
                toSQLString(_f_nonwin._base);

        
        if (DBFace::instance()->
                insert("fights", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_winner_id._dirty = false;
            _f_loser_id._dirty = false;
            _f_date._dirty = false;
            _f_event._dirty = false;
            _f_round._dirty = false;
            _f_time._dirty = false;
            _f_exists._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_finish._dirty = false;
            _f_nonwin._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Fight> _f_id;
    F_Fixnum _f_winner_id;
    F_Fixnum _f_loser_id;
    F_Time _f_date;
    F_String _f_event;
    F_Fixnum _f_round;
    F_Fixnum _f_time;
    F_Object _f_exists;
    F_Time _f_created_at;
    F_Time _f_updated_at;
    F_String _f_finish;
    F_Fixnum _f_nonwin;

    friend class T_Fight;
};

} //namespace DMMM
#endif //O_FIGHT
