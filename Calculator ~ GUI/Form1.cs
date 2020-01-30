using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace Calculator___GUI
{
    public partial class MainForm : Form
    {
        string titleAPP = "Calculator ~ GUI";

        public MainForm()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e){
            this.Text = titleAPP;
            this.MinimizeBox = false;
        }

        private void fixedSize(object sender , EventArgs e) {

            this.Size = new Size(415, 228);
        }

        private void button1_Click(object sender, EventArgs e){

            try {

                NormalCalculatorForm NormalCalcForm = new NormalCalculatorForm();
                NormalCalcForm.ShowDialog();

            }
            catch(Exception error) {
                MessageBox.Show("Error : " + error);
            }
            
        }

        private void programmerCalculator_Click(object sender, EventArgs e){

            ProgrammerCalculatorForm ProgrammerCalc = new ProgrammerCalculatorForm();

            ProgrammerCalc.ShowDialog();

        }

        private void button1_Click_1(object sender, EventArgs e){

            aboutForm aboutFRM = new aboutForm();

            aboutFRM.ShowDialog();

        }
    }
}
