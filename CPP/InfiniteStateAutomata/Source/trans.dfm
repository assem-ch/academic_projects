object addtrans: Taddtrans
  Left = 308
  Top = 254
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'TRANSITION'
  ClientHeight = 66
  ClientWidth = 312
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 96
    Top = 8
    Width = 18
    Height = 13
    Caption = 'Mot'
  end
  object Label2: TLabel
    Left = 8
    Top = 8
    Width = 34
    Height = 13
    Caption = 'etat init'
  end
  object Label3: TLabel
    Left = 208
    Top = 8
    Width = 29
    Height = 13
    Caption = 'etatfin'
  end
  object OK: TButton
    Left = 262
    Top = 24
    Width = 43
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = OKClick
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 24
    Width = 57
    Height = 21
    ImeMode = imClose
    ItemHeight = 13
    Sorted = True
    TabOrder = 1
  end
  object ComboBox2: TComboBox
    Left = 200
    Top = 24
    Width = 57
    Height = 21
    ItemHeight = 13
    TabOrder = 2
  end
  object Edit1: TComboBox
    Left = 72
    Top = 24
    Width = 121
    Height = 21
    ItemHeight = 13
    TabOrder = 3
  end
end
