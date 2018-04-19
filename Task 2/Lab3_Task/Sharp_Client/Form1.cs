using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Reflection;
using System.Diagnostics;
using Lab3_Task_ServerLib;

namespace Sharp_Client
{
    public partial class Form1 : Form
    {
        const Int32 ITERATIONS = 500000; 
        public Form1()
        {
            InitializeComponent();
        }
        // Реализация позднего связывания
         private void buttonLate_Click(object sender, EventArgs e)
        {
            int iParam1, iParam2, iParam3, rezFun121;
            double dParam1, dParam2, rezFun123;
            float rezFun122;
            try
            {
                dParam1 = Convert.ToDouble(textBoxParam1.Text);
                dParam2 = Convert.ToDouble(textBoxParam2.Text);
                iParam1 = Convert.ToInt32(dParam1);
                iParam2 = Convert.ToInt32(dParam2);
                iParam3 = Convert.ToInt32(textBoxParam3.Text);
                Stopwatch stopWatch = new Stopwatch();
                stopWatch.Start();
                Type typeCom = Type.GetTypeFromProgID("Lab3_Task.Fun.1");
                object objCom = Activator.CreateInstance(typeCom);

                rezFun121 = (int)typeCom.InvokeMember("Fun121", BindingFlags.Public | BindingFlags.InvokeMethod, null, objCom, new object[2] { dParam1, dParam2 });
                rezFun122 = (float)typeCom.InvokeMember("Fun122", BindingFlags.Public | BindingFlags.InvokeMethod, null, objCom, new object[3] { iParam1, iParam2, iParam3 });
                rezFun123 = (double)typeCom.InvokeMember("Fun123", BindingFlags.Public | BindingFlags.InvokeMethod, null, objCom, new object[1] { dParam1 });
                textBoxFun121.Text = dParam1.ToString() + " + " + dParam2.ToString() + " = " + rezFun121.ToString();
                textBoxFun122.Text = iParam1.ToString() + " / " + iParam2.ToString() + " / " + iParam3.ToString() + " = " + rezFun122.ToString();
                textBoxFun123.Text = dParam1.ToString() + " * " + dParam1.ToString() + " = " + rezFun123.ToString();
                for (int i = 0; i < ITERATIONS; i++)
                {
                    typeCom.InvokeMember("Fun121", BindingFlags.Public | BindingFlags.InvokeMethod, null, objCom, new object[2] { dParam1, dParam2 });
                    typeCom.InvokeMember("Fun122", BindingFlags.Public | BindingFlags.InvokeMethod, null, objCom, new object[3] { iParam1, iParam2, iParam3 });
                    typeCom.InvokeMember("Fun123", BindingFlags.Public | BindingFlags.InvokeMethod, null, objCom, new object[1] { dParam1 });
                }
                stopWatch.Stop();
                TimeSpan timeWork = stopWatch.Elapsed;
                string strTimeWork = String.Format("{0:00}:{1:00}:{2:00}.{3:0000}", timeWork.Hours, timeWork.Minutes, timeWork.Seconds, timeWork.Milliseconds);
                textBoxTimeLate.Text = strTimeWork;
            }
            catch (FormatException ob)
            {
                MessageBox.Show(ob.Message);
            }
            catch (OverflowException ob)
            {
                MessageBox.Show(ob.Message);
            }
            catch (ArgumentException ob)
            {
                MessageBox.Show(ob.Message);
            }
            catch (Exception ob) {
                MessageBox.Show(ob.Message);
            }
        }
        // реализация раннего связывания по ID
         private void buttonID_Click(object sender, EventArgs e)
         {

             CoFun objFun;
             int iParam1, iParam2, iParam3, rezFun121;
             double dParam1, dParam2, rezFun123;
             float rezFun122;
             try
             {
                 dParam1 = Convert.ToDouble(textBoxParam1.Text);
                 dParam2 = Convert.ToDouble(textBoxParam2.Text);
                 iParam1 = Convert.ToInt32(dParam1);
                 iParam2 = Convert.ToInt32(dParam2);
                 iParam3 = Convert.ToInt32(textBoxParam3.Text);
                 Stopwatch stopWatch = new Stopwatch();
                 stopWatch.Start();
                 objFun = new CoFun();
                 rezFun121 = objFun.Fun121(dParam1, dParam2);
                 rezFun122 = objFun.Fun122(iParam1, iParam2, iParam3);
                 rezFun123 = objFun.Fun123(dParam1);
                 textBoxFun121.Text = dParam1.ToString() + " + " + dParam2.ToString() + " = " + rezFun121.ToString();
                 textBoxFun122.Text = iParam1.ToString() + " / " + iParam2.ToString() + " / " + iParam3.ToString() + " = " + rezFun122.ToString();
                 textBoxFun123.Text = dParam1.ToString() + " * " + dParam1.ToString() + " = " + rezFun123.ToString();
                 for (int i = 0; i < ITERATIONS; i++)
                 {
                     objFun.Fun121(dParam1, dParam2);
                     objFun.Fun122(iParam1, iParam2, iParam3);
                     objFun.Fun123(dParam1);
                 }
                 stopWatch.Stop();
                 TimeSpan timeWork = stopWatch.Elapsed;
                 string strTimeWork = String.Format("{0:00}:{1:00}:{2:00}.{3:0000}", timeWork.Hours, timeWork.Minutes, timeWork.Seconds, timeWork.Milliseconds);
                 textBoxTimeID.Text = strTimeWork;

             }
             catch (FormatException ob)
             {
                 MessageBox.Show(ob.Message);
             }
             catch (OverflowException ob)
             {
                 MessageBox.Show(ob.Message);
             }
             catch (ArgumentException ob)
             {
                 MessageBox.Show(ob.Message);
             }
             catch (Exception ob)
             {
                 MessageBox.Show(ob.Message);
             }
         }
        // Реализация раннего связывания через vTable
         private void buttonVtbl_Click(object sender, EventArgs e)
         {
             CoFun objFun = new CoFun();
             int iParam1, iParam2, iParam3, rezFun121;
             double dParam1, dParam2, rezFun123;
             float rezFun122;
             try
             {
                 dParam1 = Convert.ToDouble(textBoxParam1.Text);
                 dParam2 = Convert.ToDouble(textBoxParam2.Text);
                 iParam1 = Convert.ToInt32(dParam1);
                 iParam2 = Convert.ToInt32(dParam2);
                 iParam3 = Convert.ToInt32(textBoxParam3.Text);
                 Stopwatch stopWatch = new Stopwatch();
                 stopWatch.Start();                 
                 rezFun121 = objFun.Fun121(dParam1, dParam2);
                 rezFun122 = objFun.Fun122(iParam1, iParam2, iParam3);
                 rezFun123 = objFun.Fun123(dParam1);
                 textBoxFun121.Text = dParam1.ToString() + " + " + dParam2.ToString() + " = " + rezFun121.ToString();
                 textBoxFun122.Text = iParam1.ToString() + " / " + iParam2.ToString() + " / " + iParam3.ToString() + " = " + rezFun122.ToString();
                 textBoxFun123.Text = dParam1.ToString() + " * " + dParam1.ToString() + " = " + rezFun123.ToString();
                 for (int i = 0; i < ITERATIONS; i++)
                 {
                     objFun.Fun121(dParam1, dParam2);
                     objFun.Fun122(iParam1, iParam2, iParam3);
                     objFun.Fun123(dParam1);
                 }
                 stopWatch.Stop();
                 TimeSpan timeWork = stopWatch.Elapsed;
                 string strTimeWork = String.Format("{0:00}:{1:00}:{2:00}.{3:0000}", timeWork.Hours, timeWork.Minutes, timeWork.Seconds, timeWork.Milliseconds);
                 textBoxTimeVtbl.Text = strTimeWork;

             }
             catch (FormatException ob)
             {
                 MessageBox.Show(ob.Message);
             }
             catch (OverflowException ob)
             {
                 MessageBox.Show(ob.Message);
             }
             catch (ArgumentException ob)
             {
                 MessageBox.Show(ob.Message);
             }
             catch (Exception ob)
             {
                 MessageBox.Show(ob.Message);
             }
         }
    }
}
