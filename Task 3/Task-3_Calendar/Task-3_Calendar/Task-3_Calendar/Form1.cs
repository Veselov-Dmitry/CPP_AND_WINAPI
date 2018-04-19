using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Task_3_Calendar
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            InitializeClock();
            
        }

        private void monthCalendar1_DateChanged(object sender, DateRangeEventArgs e)
        {
            DateTime time = e.Start;
            textBoxDay.Text = time.Day.ToString();
            textBoxMonth.Text = time.Month.ToString();
            textBoxYear.Text = time.Year.ToString();
            //int t;

        }

        private void InitializeClock() {
            textBoxDay.Text = monthCalendar1.TodayDate.Day.ToString();
            textBoxMonth.Text = monthCalendar1.TodayDate.Month.ToString();
            textBoxYear.Text = monthCalendar1.TodayDate.Year.ToString();

        }

        private void buttonIns_Click(object sender, EventArgs e)
        {
            string strTime;
            DateTime instDate = new DateTime();
            try
            {
                strTime = textBoxDay.Text + ".";
                strTime += textBoxMonth.Text + ".";
                strTime += textBoxYear.Text;
                instDate = Convert.ToDateTime(strTime);
                monthCalendar1.TodayDate = instDate;
                monthCalendar1.SetDate(instDate);

            }
            catch (Exception er) {
                MessageBox.Show(er.Message);
            }
        }

        private void buttonBackGround_Click(object sender, EventArgs e)
        {
            try
            {
                ColorDialog colorDialog = new ColorDialog();
                colorDialog.ShowDialog();
                this.monthCalendar1.BackColor = colorDialog.Color;                
                
            }
            catch (Exception er)
            {
                MessageBox.Show(er.Message);
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
