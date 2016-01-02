/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SearchCriteriaModel.cpp
 * Author: max
 * 
 * Created on 2. Januar 2016, 16:59
 */

#include "SearchCriteriaModel.h"

using namespace std;
using namespace my;

SearchCriteriaModel::SearchCriteriaModel( ) 
{
  
}

void SearchCriteriaModel::setSearchFrom( my::MyDate _searchFrom ) {
    this->_searchFrom = _searchFrom;
}

my::MyDate SearchCriteriaModel::getSearchFrom( ) const {
    return _searchFrom;
}

void SearchCriteriaModel::setValue( std::string value ) {
    this->_value = value;
}

std::string SearchCriteriaModel::getValue( ) const {
    return _value;
}

void SearchCriteriaModel::setIndexes( std::vector<std::string> indexes ) {
    this->_indexes = indexes;
}

vector<string> SearchCriteriaModel::getIndexes( ) {
    return _indexes;
}

void SearchCriteriaModel::setV2Tables( std::vector<std::string> v2tables ) {
    _v2tables = v2tables;
}

std::vector<std::string> SearchCriteriaModel::getV2Tables( ) const {
    return _v2tables;
}
