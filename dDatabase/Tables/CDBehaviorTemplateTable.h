#pragma once

// Custom Classes
#include "CDTable.h"

/*!
 \file CDBehaviorTemplateTable.hpp
 \brief Contains data for the BehaviorTemplate table
 */

//! BehaviorTemplate Entry Struct
struct CDBehaviorTemplate {
    unsigned int behaviorID;                //!< The Behavior ID
    unsigned int templateID;                //!< The Template ID (LOT)
    unsigned int effectID;                  //!< The Effect ID attached
    std::string effectHandle;          //!< The effect handle
};


//! BehaviorTemplate table
class CDBehaviorTemplateTable : public CDTable {
private:
    std::vector<CDBehaviorTemplate> entries;
    
public:
    
    //! Constructor
    CDBehaviorTemplateTable(void);
    
    //! Destructor
    ~CDBehaviorTemplateTable(void);
    
    //! Returns the table's name
    /*!
      \return The table name
     */
    std::string GetName(void) const override;
    
    //! Queries the table with a custom "where" clause
    /*!
      \param predicate The predicate
     */
    std::vector<CDBehaviorTemplate> Query(std::function<bool(CDBehaviorTemplate)> predicate);
    
    //! Gets all the entries in the table
    /*!
       \return The entries
     */
    std::vector<CDBehaviorTemplate> GetEntries(void) const;
    
};
