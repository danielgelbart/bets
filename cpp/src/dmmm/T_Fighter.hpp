
#ifndef T_FIGHTER
#define T_FIGHTER
#include "O_Fighter.hpp"

namespace DMMM {

class T_Fighter{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Fighter() 
    {
        _tables.push_back("fighters");
    }
    T_Fighter(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("fighters");
    }

    
    struct E_id{
        E_id() 
        {  
            _field = "fighters.id";
        }
        std::string _field;
        typedef T_Fighter::Condition ConditionType;
        typedef Field<I_Fighter>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_name{
        E_name() 
        {  
            _field = "fighters.name";
        }
        std::string _field;
        typedef T_Fighter::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_name _name(){ 
        return E_name();
    }
    struct E_created_at{
        E_created_at() 
        {  
            _field = "fighters.created_at";
        }
        std::string _field;
        typedef T_Fighter::Condition ConditionType;
        typedef F_Time::Base ComparerType;
    };

    static E_created_at _created_at(){ 
        return E_created_at();
    }
    struct E_updated_at{
        E_updated_at() 
        {  
            _field = "fighters.updated_at";
        }
        std::string _field;
        typedef T_Fighter::Condition ConditionType;
        typedef F_Time::Base ComparerType;
    };

    static E_updated_at _updated_at(){ 
        return E_updated_at();
    }
    struct E_full_data{
        E_full_data() 
        {  
            _field = "fighters.full_data";
        }
        std::string _field;
        typedef T_Fighter::Condition ConditionType;
        typedef F_Object::Base ComparerType;
    };

    static E_full_data _full_data(){ 
        return E_full_data();
    }
    struct E_url{
        E_url() 
        {  
            _field = "fighters.url";
        }
        std::string _field;
        typedef T_Fighter::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_url _url(){ 
        return E_url();
    }
    struct E_for_delete{
        E_for_delete() 
        {  
            _field = "fighters.for_delete";
        }
        std::string _field;
        typedef T_Fighter::Condition ConditionType;
        typedef F_Object::Base ComparerType;
    };

    static E_for_delete _for_delete(){ 
        return E_for_delete();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("name");
        ret.push_back("created_at");
        ret.push_back("updated_at");
        ret.push_back("full_data");
        ret.push_back("url");
        ret.push_back("for_delete");
        return ret;
    }

    std::vector<O_Fighter> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Fighter> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Fighter>::Base>(res[i]["id"]);
            ret[i]._f_name._base =
                UTILS::fromString<F_String::Base>(res[i]["name"]);
            ret[i]._f_created_at._base =
                UTILS::fromString<F_Time::Base>(res[i]["created_at"]);
            ret[i]._f_updated_at._base =
                UTILS::fromString<F_Time::Base>(res[i]["updated_at"]);
            ret[i]._f_full_data._base =
                UTILS::fromString<F_Object::Base>(res[i]["full_data"]);
            ret[i]._f_url._base =
                UTILS::fromString<F_String::Base>(res[i]["url"]);
            ret[i]._f_for_delete._base =
                UTILS::fromString<F_Object::Base>(res[i]["for_delete"]);
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


    std::vector<O_Fighter> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Fighter> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Fighter> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Fighter, bool> select(const I_Fighter& id){
        return first(E_id() == id);
    }

    std::pair<O_Fighter, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Fighter> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Fighter(), false);
    }

    std::pair<O_Fighter, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Fighter>::const_iterator begin,
                         std::vector<O_Fighter>::const_iterator end)
    {
	std::vector<std::string> fields;
                

        fields.push_back(std::string("name"));
        

        fields.push_back(std::string("created_at"));
        

        fields.push_back(std::string("updated_at"));
        

        fields.push_back(std::string("full_data"));
        

        fields.push_back(std::string("url"));
        

        fields.push_back(std::string("for_delete"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Fighter& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._name()));
            
            row.push_back(toSQLString(r._created_at()));
            
            row.push_back(toSQLString(r._updated_at()));
            
            row.push_back(toSQLString(r._full_data()));
            
            row.push_back(toSQLString(r._url()));
            
            row.push_back(toSQLString(r._for_delete()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("fighters",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Fighter>::const_iterator begin,
                           std::vector<O_Fighter>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Fighter>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        

            if (it->_f_name._dirty){
                fields.push_back(std::string("name"));
                row.push_back(toSQLString(it->_name()));
            }
            

            if (it->_f_created_at._dirty){
                fields.push_back(std::string("created_at"));
                row.push_back(toSQLString(it->_created_at()));
            }
            

            if (it->_f_updated_at._dirty){
                fields.push_back(std::string("updated_at"));
                row.push_back(toSQLString(it->_updated_at()));
            }
            

            if (it->_f_full_data._dirty){
                fields.push_back(std::string("full_data"));
                row.push_back(toSQLString(it->_full_data()));
            }
            

            if (it->_f_url._dirty){
                fields.push_back(std::string("url"));
                row.push_back(toSQLString(it->_url()));
            }
            

            if (it->_f_for_delete._dirty){
                fields.push_back(std::string("for_delete"));
                row.push_back(toSQLString(it->_for_delete()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("fighters",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_FIGHTER
