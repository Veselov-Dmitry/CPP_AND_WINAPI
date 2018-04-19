Public Class Form1
    Const ITERATIONS = 500000
    Private Sub Bt_Late_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Bt_Late.Click
        ' Пример позднего связывания 
        Dim obj As Object
        Dim i As Long
        Dim Start As DateTime = DateTime.Now
        ' Создание объекта с указанным ProgId 
        obj = CreateObject("Lb3_AutoSvr.CoMyMath.1")
        txtOp3.Text = obj.Add(txtOp1.Text, txtOp2.Text)
        For i = 1 To ITERATIONS
            obj.Add(txtOp1.Text, txtOp2.Text)
        Next
        txtTime1.Text = (DateTime.Now - Start).TotalSeconds
        obj = Nothing
    End Sub

    Private Sub Bt_ID_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Bt_ID.Click
        ' Пример ID-связывания  
        Dim obj As Lb3_AutoSvrLib.CoMyMath ' указание на TypeLib 
        Dim i As Long
        Dim Start As DateTime = DateTime.Now
        obj = New Lb3_AutoSvrLib.CoMyMath
        txtOp3.Text = obj.Add(txtOp1.Text,
txtOp2.Text)
        For i = 1 To ITERATIONS
            obj.Add(txtOp1.Text, txtOp2.Text)
        Next
        txtTime2.Text = (DateTime.Now - Start).TotalSeconds
    End Sub

    Private Sub BT_vtbl_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BT_vtbl.Click
        ' Пример связывания через vtbl(очень раннего связывания) 
        Dim i As Long
        Dim obj As New Lb3_AutoSvrLib.CoMyMath
        Dim Start As DateTime = DateTime.Now
        txtOp3.Text = obj.Add(txtOp1.Text, txtOp2.Text)
        For i = 1 To ITERATIONS
            obj.Add(txtOp1.Text, txtOp2.Text)
        Next
        txtTime3.Text = (DateTime.Now - Start).TotalSeconds

    End Sub
End Class
