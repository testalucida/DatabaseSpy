/* 
 * File:   SearchCriteriaModel.h
 * Author: max
 *
 * Created on 2. Januar 2016, 16:59
 */

#ifndef SEARCHCRITERIAMODEL_H
#define SEARCHCRITERIAMODEL_H

#include <vector>
#include <string>
#include <my/datetime.h>

class SearchCriteriaModel {
public:
    SearchCriteriaModel();
    //get/set für das Suchdatum
    void setSearchFrom(my::MyDate searchFrom);
    my::MyDate getSearchFrom() const;
    
    //get/set für den Wert der Spalte, über die gesucht wird
    void setValue(std::string value);
    std::string getValue() const;
    
    //get/set für die Indexes der V2-Tabellen
    void setIndexes(std::vector<std::string> indexes);
    std::vector<std::string> getIndexes() const;
    
    //get/set für die V2-Tabellen
    void setV2Tables(std::vector<std::string> v2tables);
    std::vector<std::string> getV2Tables() const;
    
private:
    std::vector<std::string> _v2tables;
    std::vector<std::string> _indexes;
    std::string _value;
    my::MyDate _searchFrom;
};

#endif /* SEARCHCRITERIAMODEL_H */

