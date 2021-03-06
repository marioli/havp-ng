/***************************************************************************
                          proxyhandler.h  -  description
                             -------------------
    begin                : So Feb 20 2005
    copyright            : (C) 2005 by Christian Hilgers
    email                : christian@havp.org
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef PROXYHANDLER_H
#define PROXYHANDLER_H

#include "default.h"
#include "connectiontobrowser.h"
#include "connectiontohttp.h"
#include "scannerhandler.h"

#include <string>

using namespace std;

class ProxyDetails {
private:
    bool UseParentProxy;
	string ParentHost;
	int ParentPort;
	bool UseParentProxyAuth;
	string ParentUser;
	string ParentPassword;
public:
	ProxyDetails();
	bool useProxy() {return UseParentProxy;};
	bool useProxyAuth() {return UseParentProxyAuth;};
	string getHost() {return ParentHost;};
	int getPort() {return ParentPort;};
	string getUser() {return ParentUser;};
	string getPassword() {return ParentPassword;};
};

class ProxyHandler {
private:

bool HeaderSend;
bool BrowserDropped;
bool DropBrowser;
bool ScannerUsed;
bool UnlockDone;
bool AnswerDone;
bool ReinitDone;
bool ServerClosed;
bool ServerConnected;
bool DropServer;
int alivecount;
string ConnectedHost;
int ConnectedPort;

string Header;

ConnectionToBrowser ToBrowser;
ConnectionToHTTP ToServer;
ProxyDetails parentProxy;

int MaxDownloadSize;
int KeepBackTime;
int TricklingTime;
unsigned int TricklingBytes;
int KeepBackBuffer;

int TransferredHeader;
long long TransferredBody;

bool DontLock;
bool DontLockBINHEX;
bool DontLockPDF;
bool DontLockZIP;

bool ProxyMessage( int CommunicationAnswerT, string Answer );
int CommunicationHTTP( ScannerHandler &Scanners, bool ScannerOff );
int CommunicationFTP( ScannerHandler &Scanners, bool ScannerOff );

#ifdef SSLTUNNEL
int CommunicationSSL();
#endif

public:

void Proxy( SocketHandler &ProxyServerT, ScannerHandler &Scanners );
 
ProxyHandler();
~ProxyHandler();

};

#endif
