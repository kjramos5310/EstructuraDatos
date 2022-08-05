; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Proyecto_Splay_Tree"
#define MyAppVersion "1.0"
#define MyAppPublisher "GRUPO16, Inc."
#define MyAppURL "https://www.example.com/"
#define MyAppExeName "SplayTree.exe"
#define MyAppAssocName MyAppName + " File"
#define MyAppAssocExt ".myp"
#define MyAppAssocKey StringChange(MyAppAssocName, " ", "") + MyAppAssocExt

[Setup]
; NOTE: The value of AppId uniquely identifies this application. Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{23DCA4A4-D133-42D7-BF1D-54F9CD152D89}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName=C:\Users\HP\Desktop\{#MyAppName}
ChangesAssociations=yes
DisableProgramGroupPage=yes
; Uncomment the following line to run in non administrative install mode (install for current user only.)
;PrivilegesRequired=lowest
OutputDir=C:\Users\HP\Desktop\ProyectoFinalU2
OutputBaseFilename=mysetup
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\Users\HP\Documents\ESPE\SEGUNDO SEMESTRE\SEGUNDA\Programacion\Estructura de Datos\PROYECTOU2\ele\Ahorita si sale\EstructuraDatos\Splay Tree_v1.1\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\HP\Documents\ESPE\SEGUNDO SEMESTRE\SEGUNDA\Programacion\Estructura de Datos\PROYECTOU2\ele\Ahorita si sale\EstructuraDatos\Splay Tree_v1.1\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Registry]
Root: HKA; Subkey: "Software\Classes\{#MyAppAssocExt}\OpenWithProgids"; ValueType: string; ValueName: "{#MyAppAssocKey}"; ValueData: ""; Flags: uninsdeletevalue
Root: HKA; Subkey: "Software\Classes\{#MyAppAssocKey}"; ValueType: string; ValueName: ""; ValueData: "{#MyAppAssocName}"; Flags: uninsdeletekey
Root: HKA; Subkey: "Software\Classes\{#MyAppAssocKey}\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\{#MyAppExeName},0"
Root: HKA; Subkey: "Software\Classes\{#MyAppAssocKey}\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\{#MyAppExeName}"" ""%1"""
Root: HKA; Subkey: "Software\Classes\Applications\{#MyAppExeName}\SupportedTypes"; ValueType: string; ValueName: ".myp"; ValueData: ""

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

[code]
function SetFocus(hWnd: HWND): HWND;
  external 'SetFocus@user32.dll stdcall';
function OpenClipboard(hWndNewOwner: HWND): BOOL;
  external 'OpenClipboard@user32.dll stdcall';
function GetClipboardData(uFormat: UINT): THandle;
  external 'GetClipboardData@user32.dll stdcall';
function CloseClipboard: BOOL;
  external 'CloseClipboard@user32.dll stdcall';
function GlobalLock(hMem: THandle): PAnsiChar;
  external 'GlobalLock@kernel32.dll stdcall';
function GlobalUnlock(hMem: THandle): BOOL;
  external 'GlobalUnlock@kernel32.dll stdcall';

var
  SerialPage: TWizardPage;
  SerialEdits: array of TEdit;
  SerialCorrect: array of TEdit;

const
  CF_TEXT = 1;
  VK_BACK = 8;
  SC_EDITCOUNT = 5;
  SC_CHARCOUNT = 4;
  SC_DELIMITER = '-';

function IsValidInput: Boolean;
var
  I: Integer;
begin
  Result := True;
  for I := 0 to GetArrayLength(SerialEdits) - 1 do
    if (Length(SerialEdits[I].Text) < SC_CHARCOUNT) then
    begin
      Result := False;
      Break;
    end;
end;

function IsSerialCorrect: Boolean;
var
  I: Integer;
begin              
  Result := False;         
  if (SerialEdits[0].Text  = 'ESPE') and (SerialEdits[1].Text  = '100A')and (SerialEdits[2].Text  = 'MEJO')and (SerialEdits[3].Text  = 'MIAM')and (SerialEdits[4].Text  = '54P1') then
    Result := True;   
  if (SerialEdits[0].Text  = 'RVTE') and (SerialEdits[1].Text  = 'BLAQ')and (SerialEdits[2].Text  = 'JOEM')and (SerialEdits[3].Text  = 'WPQZ')and (SerialEdits[4].Text  = 'GHT7') then
    Result := True;
  if (SerialEdits[0].Text  = 'CRIS') and (SerialEdits[1].Text  = 'BRAN')and (SerialEdits[2].Text  = 'SHAR')and (SerialEdits[3].Text  = 'SEBA')and (SerialEdits[4].Text  = 'POLU') then
    Result := True;
  if (SerialEdits[0].Text  = '1234') and (SerialEdits[1].Text  = 'GHLR')and (SerialEdits[2].Text  = 'TYLB')and (SerialEdits[3].Text  = 'ALCR')and (SerialEdits[4].Text  = 'RELT') then
    Result := True;
  if (SerialEdits[0].Text  = 'YOTL') and (SerialEdits[1].Text  = 'ER4T')and (SerialEdits[2].Text  = 'AWLC')and (SerialEdits[3].Text  = 'ELRO')and (SerialEdits[4].Text  = 'B23R') then
    Result := True;
end;

function GetClipboardText: string;
var
  Data: THandle;
begin
  Result := '';
  if OpenClipboard(0) then
  try
    Data := GetClipboardData(CF_TEXT);
    if Data <> 0 then
      Result := String(GlobalLock(Data));
  finally
    if Data <> 0 then
      GlobalUnlock(Data);
    CloseClipboard;
  end;
end;

function GetSerialNumber(ADelimiter: Char): string;
var
  I: Integer;
begin
  Result := '';
  for I := 0 to GetArrayLength(SerialEdits) - 1 do
    Result := Result + SerialEdits[I].Text + ADelimiter;
  Delete(Result, Length(Result), 1);
end;

function TrySetSerialNumber(const ASerialNumber: string; ADelimiter: Char): Boolean;
var
  I: Integer;
  J: Integer;
begin
  Result := False;

  if Length(ASerialNumber) = ((SC_EDITCOUNT * SC_CHARCOUNT) + (SC_EDITCOUNT - 1)) then
  begin
    for I := 1 to SC_EDITCOUNT - 1 do
      if ASerialNumber[(I * SC_CHARCOUNT) + I] <> ADelimiter then
        Exit;

    for I := 0 to GetArrayLength(SerialEdits) - 1 do
    begin
      J := (I * SC_CHARCOUNT) + I + 1;
      SerialEdits[I].Text := Copy(ASerialNumber, J, SC_CHARCOUNT);
    end;

    Result := True;
  end;
end;

function TryPasteSerialNumber: Boolean;
begin
  Result := TrySetSerialNumber(GetClipboardText, SC_DELIMITER);
end;

procedure OnSerialEditChange(Sender: TObject);
begin
  WizardForm.NextButton.Enabled := IsSerialCorrect;
end;

procedure OnSerialEditKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
var
  Edit: TEdit;
  EditIndex: Integer;
begin
  Edit := TEdit(Sender);
  EditIndex := Edit.TabOrder - SerialEdits[0].TabOrder;
  if (EditIndex = 0) and (Key = Ord('V')) and (Shift = [ssCtrl]) then
  begin
    if TryPasteSerialNumber then
      Key := 0;
  end
  else
  if (Key >= 32) and (Key <= 255) then
  begin
    if Length(Edit.Text) = SC_CHARCOUNT - 1 then
    begin
      if EditIndex < GetArrayLength(SerialEdits) - 1 then
        SetFocus(SerialEdits[EditIndex + 1].Handle)
      else
        SetFocus(WizardForm.NextButton.Handle);
    end;
  end
  else
  if Key = VK_BACK then
    if (EditIndex > 0) and (Edit.Text = '') and (Edit.SelStart = 0) then
      SetFocus(SerialEdits[EditIndex - 1].Handle);
end;

procedure CreateSerialNumberPage;
var
  I: Integer;
  Edit: TEdit;
  DescLabel: TLabel;
  EditWidth: Integer;
begin
  SerialPage := CreateCustomPage(wpWelcome, 'LICENCIAS',
    'Introduzca una licencia original: ');

  DescLabel := TLabel.Create(SerialPage);
  DescLabel.Top := 16;
  DescLabel.Left := 0;
  DescLabel.Parent := SerialPage.Surface;
  DescLabel.Caption := 'Introduzca una licencia v�lida! ';
  DescLabel.Font.Style := [fsBold];

  SetArrayLength(SerialEdits, SC_EDITCOUNT);
  EditWidth := (SerialPage.SurfaceWidth - ((SC_EDITCOUNT - 1) * 8)) div SC_EDITCOUNT;

  for I := 0 to SC_EDITCOUNT - 1 do
  begin
    Edit := TEdit.Create(SerialPage);
    Edit.Top := 40;
    Edit.Left := I * (EditWidth + 8);
    Edit.Width := EditWidth;
    Edit.CharCase := ecUpperCase;
    Edit.MaxLength := SC_CHARCOUNT;
    Edit.Parent := SerialPage.Surface;
    Edit.OnChange := @OnSerialEditChange;
    Edit.OnKeyDown := @OnSerialEditKeyDown;
    SerialEdits[I] := Edit;
  end;
end;

procedure CurPageChanged(CurPageID: Integer);
begin
  if CurPageID = SerialPage.ID then
    WizardForm.NextButton.Enabled := IsSerialCorrect;  
end;

procedure InitializeWizard;   
begin

  CreateSerialNumberPage;  
end;