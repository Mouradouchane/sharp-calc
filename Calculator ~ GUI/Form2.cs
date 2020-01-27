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
    public partial class ProgrammerCalculatorForm : Form
    {
        public ProgrammerCalculatorForm()
        {
            InitializeComponent();
        }

        private void fixedSize(object sender, EventArgs e)
        {

            this.Size = new Size(308, 288);
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text = "";
        }

        private void button10_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += "A";
        }

        private void ProgrammerCalculatorForm_Load(object sender, EventArgs e)
        {

        }

        private void button11_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += "B";
        }

        private void button12_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += "C";
        }

        private void button11_Click_1(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += "E";
        }

        private void button10_Click_1(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += "F";
        }

        private void buttonSum_Click(object sender, EventArgs e){

            try {
                string textValue = this.InpOutProgrammer.Text;
                
                if(this.ToBin.Checked == true){
                    this.InpOutProgrammer.Text = string.Format("0x02", textValue);
                }

                if (this.ToDec.Checked == true){

                }

                if (this.ToOct.Checked == true){

                }

                if(this.ToHex.Checked == true){

                }

            }
            catch (Exception error) {
                MessageBox.Show("Error :" + error);
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += 1;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += 2;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += 3;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += 4;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += 5;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += 6;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += 7;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += 8;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += 9;
        }

        private void buttonD_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += "D";
        }

        private void buttonDot_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += ".";
        }

        private void button0_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += 0;
        }

        private void buttonPlus_Click(object sender, EventArgs e)
        {
            this.InpOutProgrammer.Text += "+";
        }

        private void buttonEriser_Click(object sender, EventArgs e){

            char[] textVal = this.InpOutProgrammer.Text.ToCharArray();
            this.InpOutProgrammer.Text = "";
            for (int i = 0 ; i < textVal.Length - 1 ; i += 1){
                this.InpOutProgrammer.Text += textVal[i];
            }
        
        }
    }
}
