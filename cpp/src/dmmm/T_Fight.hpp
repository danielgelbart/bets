
#ifndef T_FIGHT
#define T_FIGHT
#include "O_Fight.hpp"

namespace DMMM {

class T_Fight{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Fight() 
    {
        _tables.push_back("fights");
    }
    T_Fight(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("fights");
    }

 
    T_Fight(const I_Fighter& parentId)
    {
        _tables.push_back("fights");
        
        _constraint._cond = "(fights.winner_id = " + parentId.to_s() + ")";
    } 
 
    T_Fight(const I_Fighter& parentId)
    {
        _tables.push_back("fights");
        
        _constraint._cond = "(fights.loser_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "fights.id";
        }
        std::string _field;
        typedef T_Fight::Condition ConditionType;
        typedef Field<I_Fight>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_winner_id{
        E_winner_id() 
        {  
            _field = "fights.winner_id";
        }
        std::string _field;
        typedef T_Fight::Condition ConditionType;
        typedef F_Fixnum::Base ComparerType;
    };

    static E_winner_id _winner_id(){ 
        return E_winner_id();
    }
    struct E_loser_id{
        E_loser_id() 
        {  
            _field = "fights.loser_id";
        }
        std::string _field;
        typedef T_Fight::Condition ConditionType;
        typedef F_Fixnum::Base ComparerType;
    };

    static E_loser_id _loser_id(){ 
        return E_loser_id();
    }
    struct E_date{
        E_date() 
        {  
            _field = "fights.date";
        }
        std::string _field;
        typedef T_Fight::Condition ConditionType;
        typedef F_Time::Base ComparerType;
    };

    static E_date _date(){ 
        return E_date();
    }
    struct E_event{
        E_event() 
        {  
            _field = "fights.event";
        }
        std::string _field;
        typedef T_Fight::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_event _event(){ 
        return E_event();
    }
    struct E_round{
        E_round() 
        {  
            _field = "fights.round";
        }
        std::string _field;
        typedef T_Fight::Condition ConditionType;
        typedef F_Fixnum::Base ComparerType;
    };

    static E_round _round(){ 
        return E_round();
    }
    struct E_time{
        E_time() 
        {  
            _field = "fights.time";
        }
        std::string _field;
        typedef T_Fight::Condition ConditionType;
        typedef F_Fixnum::Base ComparerType;
    };

    static E_time _time(){ 
        return E_time();
    }
    struct E_exists{
        E_exists() 
        {  
            _field = "fights.exists";
        }
        std::string _field;
        typedef T_Fight::Condition ConditionType;
        typedef F_Object::Base ComparerType;
    };

    static E_exists _exists(){ 
        return E_exists();
    }
    struct E_created_at{
        E_created_at() 
        {  
            _field = "fights.created_at";
        }
        std::string _field;
        typedef T_Fight::Condition ConditionType;
        typedef F_Time::Base ComparerType;
    };

    static E_created_at _created_at(){ 
        return E_created_at();
    }
    struct E_updated_at{
        E_updated_at() 
        {  
            _field = "fights.updated_at";
        }
        std::string _field;
        typedef T_Fight::Condition ConditionType;
        typedef F_Time::Base ComparerType;
    };

    static E_updated_at _updated_at(){ 
        return E_updated_at();
    }
    struct E_finish{
        E_finish() 
        {  
            _field = "fights.finish";
        }
        std::string _field;
        typedef T_Fight::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_finish _finish(){ 
        return E_finish();
    }
    struct E_nonwin{
        E_nonwin() 
        {  
            _field = "fights.nonwin";
        }
        std::string _field;
        typedef T_Fight::Condition ConditionType;
        typedef F_Fixnum::Base ComparerType;
    };

    static E_nonwin _nonwin(){ 
        return E_nonwin();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("winner_id");
        ret.push_back("loser_id");
        ret.push_back("date");
        ret.push_back("event");
        ret.push_back("round");
        ret.push_back("time");
        ret.push_back("exists");
        ret.push_back("created_at");
        ret.push_back("updated_at");
        ret.push_back("finish");
        ret.push_back("nonwin");
        return ret;
    }

    std::vector<O_Fight> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Fight> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Fight>::Base>(res[i]["id"]);
            ret[i]._f_winner_id._base =
                UTILS::fromString<F_Fixnum::Base>(res[i]["winner_id"]);
            ret[i]._f_loser_id._base =
                UTILS::fromString<F_Fixnum::Base>(res[i]["loser_id"]);
            ret[i]._f_date._base =
                UTILS::fromString<F_Time::Base>(res[i]["date"]);
            ret[i]._f_event._base =
                UTILS::fromString<F_String::Base>(res[i]["event"]);
            ret[i]._f_round._base =
                UTILS::fromString<F_Fixnum::Base>(res[i]["round"]);
            ret[i]._f_time._base =
                UTILS::fromString<F_Fixnum::Base>(res[i]["time"]);
            ret[i]._f_exists._base =
                UTILS::fromString<F_Object::Base>(res[i]["exists"]);
            ret[i]._f_created_at._base =
                UTILS::fromString<F_Time::Base>(res[i]["created_at"]);
            ret[i]._f_updated_at._base =
                UTILS::fromString<F_Time::Base>(res[i]["updated_at"]);
            ret[i]._f_finish._base =
                UTILS::fromString<F_String::Base>(res[i]["finish"]);
            ret[i]._f_nonwin._base =
                UTILS::fromString<F_Fixnum::Base>(res[i]["nonwin"]);
        }
        return ret;
    }

    size_t count(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return DBFace::instance()->count(_tables, c1._cond);
    }

    void erase(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        DBFace::instance()->erase(_tables, c1._cond);
    }

    void erase()
    {   
        DBFace::instance()->erase(_tables, _constraint._cond);
    }


    std::vector<O_Fight> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Fight> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Fight> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Fight, bool> select(const I_Fight& id){
        return first(E_id() == id);
    }

    std::pair<O_Fight, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Fight> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Fight(), false);
    }

    std::pair<O_Fight, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Fight>::const_iterator begin,
                         std::vector<O_Fight>::const_iterator end)
    {
	std::vector<std::string> fields;
                

        fields.push_back(std::string("winner_id"));
        

        fields.push_back(std::string("loser_id"));
        

        fields.push_back(std::string("date"));
        

        fields.push_back(std::string("event"));
        

        fields.push_back(std::string("round"));
        

        fields.push_back(std::string("time"));
        

        fields.push_back(std::string("exists"));
        

        fields.push_back(std::string("created_at"));
        

        fields.push_back(std::string("updated_at"));
        

        fields.push_back(std::string("finish"));
        

        fields.push_back(std::string("nonwin"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Fight& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._winner_id()));
            
            row.push_back(toSQLString(r._loser_id()));
            
            row.push_back(toSQLString(r._date()));
            
            row.push_back(toSQLString(r._event()));
            
            row.push_back(toSQLString(r._round()));
            
            row.push_back(toSQLString(r._time()));
            
            row.push_back(toSQLString(r._exists()));
            
            row.push_back(toSQLString(r._created_at()));
            
            row.push_back(toSQLString(r._updated_at()));
            
            row.push_back(toSQLString(r._finish()));
            
            row.push_back(toSQLString(r._nonwin()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("fights",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Fight>::const_iterator begin,
                           std::vector<O_Fight>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Fight>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        

            if (it->_f_winner_id._dirty){
                fields.push_back(std::string("winner_id"));
                row.push_back(toSQLString(it->_winner_id()));
            }
            

            if (it->_f_loser_id._dirty){
                fields.push_back(std::string("loser_id"));
                row.push_back(toSQLString(it->_loser_id()));
            }
            

            if (it->_f_date._dirty){
                fields.push_back(std::string("date"));
                row.push_back(toSQLString(it->_date()));
            }
            

            if (it->_f_event._dirty){
                fields.push_back(std::string("event"));
                row.push_back(toSQLString(it->_event()));
            }
            

            if (it->_f_round._dirty){
                fields.push_back(std::string("round"));
                row.push_back(toSQLString(it->_round()));
            }
            

            if (it->_f_time._dirty){
                fields.push_back(std::string("time"));
                row.push_back(toSQLString(it->_time()));
            }
            

            if (it->_f_exists._dirty){
                fields.push_back(std::string("exists"));
                row.push_back(toSQLString(it->_exists()));
            }
            

            if (it->_f_created_at._dirty){
                fields.push_back(std::string("created_at"));
                row.push_back(toSQLString(it->_created_at()));
            }
            

            if (it->_f_updated_at._dirty){
                fields.push_back(std::string("updated_at"));
                row.push_back(toSQLString(it->_updated_at()));
            }
            

            if (it->_f_finish._dirty){
                fields.push_back(std::string("finish"));
                row.push_back(toSQLString(it->_finish()));
            }
            

            if (it->_f_nonwin._dirty){
                fields.push_back(std::string("nonwin"));
                row.push_back(toSQLString(it->_nonwin()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("fights",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_FIGHT
