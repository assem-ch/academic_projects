object Form5: TForm5
  Left = 479
  Top = 453
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'SUPPRIMMER UN TRANSITION'
  ClientHeight = 82
  ClientWidth = 351
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 18
    Width = 97
    Height = 25
    Caption = 'Transition'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit2: TComboBox
    Left = 128
    Top = 24
    Width = 105
    Height = 21
    ItemHeight = 13
    TabOrder = 0
  end
  object Edit3: TComboBox
    Left = 248
    Top = 24
    Width = 97
    Height = 21
    ItemHeight = 13
    TabOrder = 1
  end
  object Button1: TButton
    Left = 208
    Top = 51
    Width = 67
    Height = 25
    Caption = 'ok'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 280
    Top = 51
    Width = 59
    Height = 25
    Caption = 'Annuler'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
  end
end
