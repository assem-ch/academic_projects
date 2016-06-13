object OKBottomDlg: TOKBottomDlg
  Left = 343
  Top = 218
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'about..'
  ClientHeight = 214
  ClientWidth = 313
  Color = clWindow
  ParentFont = True
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
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 76
    Top = 24
    Width = 163
    Height = 29
    Caption = 'Seduko Maker'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object Label2: TLabel
    Left = 100
    Top = 56
    Width = 96
    Height = 29
    Caption = 'V 1.0.0.0'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object Label3: TLabel
    Left = 140
    Top = 80
    Width = 30
    Height = 29
    Caption = 'By'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object Label4: TLabel
    Left = 68
    Top = 112
    Width = 180
    Height = 29
    Caption = 'ASSEM CHELLI'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object Label5: TLabel
    Left = 55
    Top = 142
    Width = 210
    Height = 19
    Caption = 'assemchelli@maktoob.com'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 297
    Height = 161
    Shape = bsFrame
  end
  object OKBtn: TButton
    Left = 120
    Top = 180
    Width = 81
    Height = 25
    Caption = 'OK'
    Default = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ModalResult = 1
    ParentFont = False
    TabOrder = 0
    OnClick = OKBtnClick
  end
end
