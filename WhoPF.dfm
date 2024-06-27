object WPF: TWPF
  Left = 0
  Top = 0
  ClientHeight = 341
  ClientWidth = 402
  Color = clGradientInactiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 8
    Top = 24
    Width = 201
    Height = 57
    Caption = 'AI play first with x'
    Font.Charset = ANSI_CHARSET
    Font.Color = clPurple
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 186
    Top = 104
    Width = 201
    Height = 57
    Caption = 'ai play first with o   '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 176
    Width = 201
    Height = 57
    Caption = 'you play first with x'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 186
    Top = 250
    Width = 201
    Height = 57
    Caption = 'you play first with o '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Showcard Gothic'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 3
    OnClick = Button4Click
  end
end
