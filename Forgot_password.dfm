object Forgotpass: TForgotpass
  Left = 0
  Top = 0
  ClientHeight = 296
  ClientWidth = 431
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 72
    Width = 109
    Height = 26
    Caption = 'username:'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object user_edit: TEdit
    Left = 88
    Top = 112
    Width = 257
    Height = 42
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 144
    Top = 168
    Width = 137
    Height = 33
    Caption = 'retrieve '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 144
    Top = 215
    Width = 137
    Height = 33
    Caption = 'menu  '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = Button2Click
  end
end
