object Form1: TForm1
  Left = 160
  Top = 121
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  BorderWidth = 1
  Caption = 'seduko maker-by assem chelli'
  ClientHeight = 498
  ClientWidth = 654
  Color = clWindow
  DefaultMonitor = dmMainForm
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindow
  Font.Height = -21
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000000000000000000000000000000000000FF8
    FFF8FF0FF8FFF8FF0FF8FFF8FF000FF8FFF8FF0FF8FFF8FF0FF8FFF8FF000888
    88888808888888880888888888000FF8FFF8FF0FF8FFF8FF0FF8FFF8FF000FF8
    FFF8FF0FF8FFF8FF0FF8FFF8FF000FF8FFF8FF0FF8FFF8FF0FF8FFF8FF000888
    88888808888888880888888888000FF8FFF8FF0FF8FFF8FF0FF8FFF8FF000FF8
    FFF8FF0FF8FFF8FF0FF8FFF8FF00000000000000000000000000000000000FF8
    FFF8FF0FF8FFF8FF0FF8FFF8FF000FF8FFF8FF0FF8FFF8FF0FF8FFF8FF000888
    88888808888888880888888888000FF8FFF8FF0FF8FFF8FF0FF8FFF8FF000FF8
    FFF8FF0FF8FFF8FF0FF8FFF8FF000FF8FFF8FF0FF8FFF8FF0FF8FFF8FF000888
    88888808888888880888888888000FF8FFF8FF0FF8FFF8FF0FF8FFF8FF000FF8
    FFF8FF0FF8FFF8FF0FF8FFF8FF00000000000000000000000000000000000FF8
    FFF8FF0FF8FFF8FF0FF8FFF8FF000FF8FFF8FF0FF8FFF8FF0FF8FFF8FF000888
    88888808888888880888888888000FF8FFF8FF0FF8FFF8FF0FF8FFF8FF000FF8
    FFF8FF0FF8FFF8FF0FF8FFF8FF000FF8FFF8FF0FF8FFF8FF0FF8FFF8FF000888
    88888808888888880888888888000FF8FFF8FF0FF8FFF8FF0FF8FFF8FF000FF8
    FFF8FF0FF8FFF8FF0FF8FFF8FF0000000000000000000000000000000000FFFF
    FFFF000000010000000100000001000000010000000100000001000000010000
    0001000000010000000100000001000000010000000100000001000000010000
    0001000000010000000100000001000000010000000100000001000000010000
    000100000001000000010000000100000001000000010000000100000001}
  OldCreateOrder = False
  Position = poDesktopCenter
  PrintScale = poNone
  Scaled = False
  OnClick = FormClick
  OnCreate = FormCreate
  OnMouseMove = FormMouseMove
  PixelsPerInch = 96
  TextHeight = 24
  object Edit01: TEdit
    Left = 51
    Top = 20
    Width = 48
    Height = 48
    Cursor = crIBeam
    AutoSize = False
    BevelKind = bkSoft
    Color = clWhite
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clNavy
    Font.Height = -33
    Font.Name = 'Tahoma'
    Font.Style = []
    MaxLength = 1
    ParentFont = False
    ReadOnly = True
    TabOrder = 0
    Text = ' '
  end
  object GroupBox1: TGroupBox
    Left = 496
    Top = 8
    Width = 145
    Height = 65
    TabOrder = 1
    object b_build: TButton
      Left = 13
      Top = 18
      Width = 116
      Height = 39
      Caption = 'Build'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = b_buildClick
    end
  end
  object GroupBox2: TGroupBox
    Left = 496
    Top = 72
    Width = 145
    Height = 121
    TabOrder = 2
    object Label1: TLabel
      Left = 13
      Top = 30
      Width = 60
      Height = 27
      Caption = 'Level'
      Color = clWindow
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      Transparent = True
    end
    object b_hide: TButton
      Left = 13
      Top = 73
      Width = 116
      Height = 40
      Caption = 'Hide'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = b_hideClick
    end
    object t_level: TTrackBar
      Left = 72
      Top = 36
      Width = 57
      Height = 37
      Ctl3D = True
      Enabled = False
      Max = 4
      Min = 1
      ParentCtl3D = False
      Position = 1
      TabOrder = 1
      OnChange = t_levelChange
    end
  end
  object GroupBox3: TGroupBox
    Left = 496
    Top = 192
    Width = 145
    Height = 65
    TabOrder = 3
    object b_play: TButton
      Left = 13
      Top = 18
      Width = 116
      Height = 39
      Caption = 'Play'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = b_playClick
    end
  end
  object GroupBox4: TGroupBox
    Left = 496
    Top = 256
    Width = 145
    Height = 161
    TabOrder = 4
    object b_save: TButton
      Left = 13
      Top = 65
      Width = 116
      Height = 40
      Caption = 'Save'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = b_saveClick
    end
    object e_save: TEdit
      Left = 13
      Top = 22
      Width = 116
      Height = 35
      Cursor = crIBeam
      AutoSize = False
      BevelKind = bkSoft
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clNavy
      Font.Height = -20
      Font.Name = 'Tahoma'
      Font.Style = []
      HideSelection = False
      MaxLength = 10
      ParentFont = False
      TabOrder = 1
      Text = 'seduko'
      OnChange = e_saveChange
    end
    object b_open: TButton
      Left = 13
      Top = 113
      Width = 116
      Height = 40
      Caption = 'Open'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = b_openClick
    end
  end
  object GroupBox5: TGroupBox
    Left = 496
    Top = 416
    Width = 145
    Height = 65
    TabOrder = 5
    object b_about: TButton
      Left = 13
      Top = 17
      Width = 116
      Height = 40
      Caption = 'About'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = b_aboutClick
    end
  end
end
