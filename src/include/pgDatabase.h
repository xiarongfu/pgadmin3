//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// Copyright (C) 2002 - 2003, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// pgDatabase.h - PostgreSQL Database
//
//////////////////////////////////////////////////////////////////////////

#ifndef PGDATABASE_H
#define PGDATABASE_H

// wxWindows headers
#include <wx/wx.h>

// App headers
#include "pgAdmin3.h"
#include "pgObject.h"
#include "pgServer.h"
#include "pgConn.h"

// Class declarations
class pgDatabase : public pgServerObject
{
public:
    pgDatabase(const wxString& newName = wxT(""));
    ~pgDatabase();

    int GetIcon() { return PGICON_DATABASE; }
    void ShowTreeDetail(wxTreeCtrl *browser, frmMain *form=0, wxListCtrl *properties=0, wxListCtrl *statistics=0, ctlSQLBox *sqlPane=0);
    static pgObject *ReadObjects(pgCollection *collection, wxTreeCtrl *browser, const wxString &restriction=wxT(""));
    static void ShowStatistics(pgCollection *collection, wxListCtrl *statistics);
    
    pgSet *ExecuteSet(const wxString& sql) { return conn->ExecuteSet(sql); }
    wxString ExecuteScalar(const wxString& sql) { return conn->ExecuteScalar(sql); }
    bool ExecuteVoid(const wxString& sql) { return conn->ExecuteVoid(sql); }

    wxString GetPrettyOption() const { return prettyOption; }

    bool GetCreatePrivilege() const { return createPrivilege; }
    void iSetCreatePrivilege(const bool b) { createPrivilege=b; }
    wxString GetPath() const { return path; };
    void iSetPath(const wxString& newVal) { path = newVal; }
    wxString GetEncoding() const { return encoding; }
    void iSetEncoding(const wxString& newVal) { encoding = newVal; }
    wxString GetVariables() const { return variables; }
    void iSetVariables(const wxString& newVal) { variables = newVal; }
    bool GetAllowConnections() const { return allowConnections; }
    void iSetAllowConnections(bool newVal) { allowConnections = newVal; }
    bool GetConnected() const { return connected; }
    bool GetSystemObject() const;
    
    bool DropObject(wxFrame *frame, wxTreeCtrl *browser);
    bool CanMaintenance() { return true; }
    bool RequireDropConfirm() { return true; }
    pgConn *connection() { return conn; }
    int Connect();

    wxMenu *GetNewMenu();
    wxString GetSql(wxTreeCtrl *browser);
    pgObject *Refresh(wxTreeCtrl *browser, const wxTreeItemId item);

private:
    pgConn *conn;
    wxString path, encoding, variables;
    wxString prettyOption;
    bool allowConnections, connected, createPrivilege;
};

#endif
