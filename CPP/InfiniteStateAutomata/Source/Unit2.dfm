object Form2: TForm2
  Left = 265
  Top = 178
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'EXPRESSION'
  ClientHeight = 87
  ClientWidth = 337
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 417
    Height = 87
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 24
      Width = 51
      Height = 13
      Caption = 'Expression'
    end
    object Edit1: TEdit
      Left = 80
      Top = 24
      Width = 249
      Height = 21
      TabOrder = 0
      Text = 'a.b.(aUb)*'
    end
    object Button2: TButton
      Left = 264
      Top = 56
      Width = 65
      Height = 25
      Caption = 'Methode2 !'
      TabOrder = 1
      OnClick = Button8Click
    end
    object Button1: TButton
      Left = 136
      Top = 56
      Width = 49
      Height = 25
      Caption = 'Clean'
      TabOrder = 2
      OnClick = Button1Click
    end
    object Button11: TButton
      Left = 192
      Top = 56
      Width = 65
      Height = 25
      Caption = 'Methode 1'
      TabOrder = 3
      OnClick = BitBtn1Click
    end
  end
end
