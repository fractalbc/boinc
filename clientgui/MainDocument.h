// $Id$
//
// The contents of this file are subject to the BOINC Public License
// Version 1.0 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://boinc.berkeley.edu/license_1.0.txt
// 
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
// License for the specific language governing rights and limitations
// under the License. 
// 
// The Original Code is the Berkeley Open Infrastructure for Network Computing. 
// 
// The Initial Developer of the Original Code is the SETI@home project.
// Portions created by the SETI@home project are Copyright (C) 2002
// University of California at Berkeley. All Rights Reserved. 
// 
// Contributor(s):
//
// Revision History:
//
// $Log$
// Revision 1.15  2004/10/01 00:06:32  rwalton
// *** empty log message ***
//
// Revision 1.14  2004/09/29 22:20:43  rwalton
// *** empty log message ***
//
// Revision 1.13  2004/09/28 01:19:46  rwalton
// *** empty log message ***
//
// Revision 1.12  2004/09/25 21:33:23  rwalton
// *** empty log message ***
//
// Revision 1.11  2004/09/14 15:52:06  rwalton
// *** empty log message ***
//
// Revision 1.10  2004/09/10 23:17:08  rwalton
// *** empty log message ***
//
// Revision 1.9  2004/09/01 04:59:32  rwalton
// *** empty log message ***
//
// Revision 1.8  2004/08/11 23:52:12  rwalton
// *** empty log message ***
//
// Revision 1.7  2004/07/13 05:56:01  rwalton
// Hooked up the Project and Work tab for the new GUI.
//
// Revision 1.6  2004/07/12 08:46:25  rwalton
// Document parsing of the <get_state/> message
//
// Revision 1.5  2004/06/25 22:50:56  rwalton
// Client spamming server hotfix
//
// Revision 1.4  2004/05/17 22:15:09  rwalton
// *** empty log message ***
//
//

#ifndef _MAINDOCUMENT_H_
#define _MAINDOCUMENT_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "MainDocument.cpp"
#endif

#include "gui_rpc_client.h"


class CMainDocument : public wxObject
{
    DECLARE_DYNAMIC_CLASS(CMainDocument)

public:
    CMainDocument();
    ~CMainDocument();

    //
    // Global
    //
private:

    RPC_CLIENT                  rpc;

    bool                        m_bIsConnected;


    //
    // Project Tab
    //
private:

    PROJECTS                    project_status;
    float                       m_fProjectTotalResourceShare;

    wxInt32                     CachedProjectStatusUpdate();

public:

    wxInt32                     GetProjectCount();
    wxInt32                     GetProjectProjectName(wxInt32 iIndex, wxString& strBuffer);
    wxInt32                     GetProjectProjectURL(wxInt32 iIndex, wxString& strBuffer);
    wxInt32                     GetProjectAccountName(wxInt32 iIndex, wxString& strBuffer);
    wxInt32                     GetProjectTeamName(wxInt32 iIndex, wxString& strBuffer);
    wxInt32                     GetProjectTotalCredit(wxInt32 iIndex, float& fBuffer);
    wxInt32                     GetProjectAvgCredit(wxInt32 iIndex, float& fBuffer);
    wxInt32                     GetProjectResourceShare(wxInt32 iIndex,  float& fBuffer);
    wxInt32                     GetProjectTotalResourceShare(wxInt32 iIndex,  float& fBuffer);
    wxInt32                     GetProjectMinRPCTime(wxInt32 iIndex, wxInt32& iBuffer);
    bool                        IsProjectSuspended(wxInt32 iIndex);
    bool                        IsProjectRPCPending(wxInt32 iIndex);

    wxInt32                     ProjectAttach( wxString& strURL, wxString& strAccountKey );
    wxInt32                     ProjectDetach( wxString& strURL );
    wxInt32                     ProjectUpdate( wxString& strURL );
    wxInt32                     ProjectReset( wxString& strURL );
    wxInt32                     ProjectSuspend( wxString& strURL );
    wxInt32                     ProjectResume( wxString& strURL );


    //
    // Messages Tab
    //
private:

    MESSAGES                    messages;
    wxInt32                     m_iMessageSequenceNumber;

    wxInt32                     CachedMessageUpdate();

public:

    wxInt32                     GetMessageCount();
    wxInt32                     GetMessageProjectName(wxInt32 iIndex, wxString& strBuffer);
    wxInt32                     GetMessageTime(wxInt32 iIndex, wxDateTime& dtBuffer);
    wxInt32                     GetMessagePriority(wxInt32 iIndex, wxInt32& iBuffer);
    wxInt32                     GetMessageMessage(wxInt32 iIndex, wxString& strBuffer);


private:

    CC_STATE                    state;
    RESULTS                     results;
    FILE_TRANSFERS              ft;
    wxDateTime                  m_dtCachedStateTimestamp;
    wxDateTime                  m_dtCachedStateLockTimestamp;
    bool                        m_bCachedStateLocked;

    wxInt32                     CachedStateUpdate();

public:

    wxInt32                     CachedStateLock();
    wxInt32                     CachedStateUnlock();

    wxInt32                     GetWorkCount();
    wxString                    GetWorkProjectName(wxInt32 iIndex);
    wxString                    GetWorkApplicationName(wxInt32 iIndex);
    wxString                    GetWorkName(wxInt32 iIndex);
    wxString                    GetWorkCPUTime(wxInt32 iIndex);
    wxString                    GetWorkProgress(wxInt32 iIndex);
    wxString                    GetWorkTimeToCompletion(wxInt32 iIndex);
    wxString                    GetWorkReportDeadline(wxInt32 iIndex);
    wxString                    GetWorkStatus(wxInt32 iIndex);

    wxInt32                     GetTransferCount();
    wxString                    GetTransferFileName(wxInt32 iIndex);
    wxString                    GetTransferProgress(wxInt32 iIndex);
    wxString                    GetTransferProjectName(wxInt32 iIndex);
    wxString                    GetTransferSize(wxInt32 iIndex);
    wxString                    GetTransferSpeed(wxInt32 iIndex);
    wxString                    GetTransferStatus(wxInt32 iIndex);
    wxString                    GetTransferTime(wxInt32 iIndex);

};

#endif

