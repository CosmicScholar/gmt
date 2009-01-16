; Script generated by the Inno Setup Script Wizard.
; $Id: GMTsetup_pdf.iss,v 1.7 2009-01-16 00:10:37 guru Exp $
; Creates Setup file for the GMT PDF documentation only
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=GMT
AppId=gmt4win
AppVerName=GMT 4.4.0
AppVersion=4.4.0
AppPublisherURL=http://gmt.soest.hawaii.edu
AppUpdatesURL=http://gmt.soest.hawaii.edu
DefaultDirName={sd}\programs\GMT
DefaultGroupName=GMT
AllowNoIcons=true
LicenseFile=c:\GMT\guru\gpl.txt
OutputBaseFilename=GMT4.4.0_pdf_install
MinVersion=0,4.0.1381
OutputDir=Y:\UH\RESEARCH\PROJECTS\GMTdev\GMT\ftp

[Files]
Source: c:\GMT\COPYING; DestDir: {app}; Flags: ignoreversion
Source: c:\GMT\www\gmt\doc\pdf\*.pdf; DestDir: {app}\www\gmt\doc\html; Flags: ignoreversion

[Messages]
WelcomeLabel2=This will install the optional PDF documentation for [name/ver] on your computer.%n%nYou should already have completed the basic GMT installation.
LicenseAccepted=I have no choice but to &accept the agreement

