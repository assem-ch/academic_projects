object Form3: TForm3
  Left = 394
  Top = 287
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Alphabets'
  ClientHeight = 55
  ClientWidth = 226
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
  object Label12: TLabel
    Left = 8
    Top = 16
    Width = 13
    Height = 13
    Caption = 'X='
  end
  object BitBtn1: TBitBtn
    Left = 191
    Top = 16
    Width = 26
    Height = 23
    Caption = 'ok'
    ModalResult = 8
    TabOrder = 0
    OnClick = BitBtn1Click
    NumGlyphs = 2
  end
  object textYard: TEdit
    Left = 24
    Top = 16
    Width = 161
    Height = 21
    TabOrder = 1
    Text = 'ab'
  end
end
