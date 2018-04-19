Public Class Form1
    Const ITERATIONS = 500000
    ' Реализация позднего связывания
    Private Sub ButtonLate_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ButtonLate.Click
        Dim obj As Object
        Dim i As Long
        Dim intRrez As Integer
        Dim floatRez, doubleRez As Double
        Dim Start As DateTime = DateTime.Now
        ' Создание объекта с указанным ProgId 
        obj = CreateObject("Lab3_Task.Fun.1")
        intRrez = obj.Fun121(TextBoxParam1.Text, TextBoxParam2.Text)
        floatRez = obj.Fun122(TextBoxParam1.Text, TextBoxParam2.Text, TextBoxParam3.Text)
        doubleRez = obj.Fun123(TextBoxParam1.Text)
        TextBoxFun121.Text = TextBoxParam1.Text & " + " & TextBoxParam2.Text & " = " & intRrez
        TextBoxFun122.Text = TextBoxParam1.Text & " / " & TextBoxParam2.Text & " / " & TextBoxParam3.Text & " = " & floatRez
        TextBoxFun123.Text = TextBoxParam1.Text & " * " & TextBoxParam1.Text & " = " & doubleRez
        For i = 1 To ITERATIONS
            obj.Fun121(TextBoxParam1.Text, TextBoxParam2.Text)
            obj.Fun122(TextBoxParam1.Text, TextBoxParam2.Text, TextBoxParam3.Text)
            obj.Fun123(TextBoxParam1.Text)
        Next
        TextBoxTimeLate.Text = (DateTime.Now - Start).TotalSeconds
        obj = Nothing
    End Sub
    ' Реализация быстрогосвязывания по ID 
    Private Sub ButtonID_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ButtonID.Click
        Dim obj As Lab3_Task_ServerLib.CoFun
        Dim i As Long
        Dim intRrez As Integer
        Dim floatRez, doubleRez As Double
        Dim Start As DateTime = DateTime.Now
        obj = New Lab3_Task_ServerLib.CoFun

        intRrez = obj.Fun121(TextBoxParam1.Text, TextBoxParam2.Text)
        floatRez = obj.Fun122(TextBoxParam1.Text, TextBoxParam2.Text, TextBoxParam3.Text)
        doubleRez = obj.Fun123(TextBoxParam1.Text)
        TextBoxFun121.Text = TextBoxParam1.Text & " + " & TextBoxParam2.Text & " = " & intRrez.ToString()
        TextBoxFun122.Text = TextBoxParam1.Text & " / " & TextBoxParam2.Text & " / " & TextBoxParam3.Text & " = " & floatRez.ToString()
        TextBoxFun123.Text = TextBoxParam1.Text & " * " & TextBoxParam1.Text & " = " & doubleRez.ToString()
        For i = 1 To ITERATIONS
            obj.Fun121(TextBoxParam1.Text, TextBoxParam2.Text)
            obj.Fun122(TextBoxParam1.Text, TextBoxParam2.Text, TextBoxParam3.Text)
            obj.Fun123(TextBoxParam1.Text)
        Next
        TextBoxTimeID.Text = (DateTime.Now - Start).TotalSeconds
    End Sub
    ' Реализация быстрого связывания через vTable
    Private Sub ButtonVtbl_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ButtonVtbl.Click
        Dim i As Long
        Dim obj As New Lab3_Task_ServerLib.CoFun
        Dim intRrez As Integer
        Dim floatRez, doubleRez As Double
        Dim Start As DateTime = DateTime.Now
        intRrez = obj.Fun121(TextBoxParam1.Text, TextBoxParam2.Text)
        floatRez = obj.Fun122(TextBoxParam1.Text, TextBoxParam2.Text, TextBoxParam3.Text)
        doubleRez = obj.Fun123(TextBoxParam1.Text)
        TextBoxFun121.Text = TextBoxParam1.Text & " + " & TextBoxParam2.Text & " = " & intRrez
        TextBoxFun122.Text = TextBoxParam1.Text & " / " & TextBoxParam2.Text & " / " & TextBoxParam3.Text & " = " & floatRez
        TextBoxFun123.Text = TextBoxParam1.Text & " * " & TextBoxParam1.Text & " = " & doubleRez
        For i = 1 To ITERATIONS
            obj.Fun121(TextBoxParam1.Text, TextBoxParam2.Text)
            obj.Fun122(TextBoxParam1.Text, TextBoxParam2.Text, TextBoxParam3.Text)
            obj.Fun123(TextBoxParam1.Text)
        Next
        TextBoxTimeVtbl.Text = (DateTime.Now - Start).TotalSeconds
    End Sub
End Class
