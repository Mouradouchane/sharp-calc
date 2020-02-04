namespace Calculator___GUI
{
    partial class ProgrammerCalculatorForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ProgrammerCalculatorForm));
            this.Input = new System.Windows.Forms.TextBox();
            this.buttonClear = new System.Windows.Forms.Button();
            this.buttonEriser = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.buttonSum = new System.Windows.Forms.Button();
            this.button0 = new System.Windows.Forms.Button();
            this.buttonA = new System.Windows.Forms.Button();
            this.buttonB = new System.Windows.Forms.Button();
            this.buttonC = new System.Windows.Forms.Button();
            this.buttonD = new System.Windows.Forms.Button();
            this.buttonE = new System.Windows.Forms.Button();
            this.buttonF = new System.Windows.Forms.Button();
            this.output = new System.Windows.Forms.TextBox();
            this.OperationType = new System.Windows.Forms.ListBox();
            this.HiddenInfo = new System.Windows.Forms.ToolTip(this.components);
            this.SuspendLayout();
            // 
            // Input
            // 
            this.Input.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.Input.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.Input.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Input.ForeColor = System.Drawing.Color.White;
            this.Input.Location = new System.Drawing.Point(12, 12);
            this.Input.Name = "Input";
            this.Input.ReadOnly = true;
            this.Input.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.Input.Size = new System.Drawing.Size(190, 20);
            this.Input.TabIndex = 0;
            this.HiddenInfo.SetToolTip(this.Input, "input value");
            // 
            // buttonClear
            // 
            this.buttonClear.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.buttonClear.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonClear.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonClear.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonClear.Location = new System.Drawing.Point(12, 83);
            this.buttonClear.Name = "buttonClear";
            this.buttonClear.Size = new System.Drawing.Size(110, 33);
            this.buttonClear.TabIndex = 46;
            this.buttonClear.Text = "C";
            this.HiddenInfo.SetToolTip(this.buttonClear, "clear input value");
            this.buttonClear.UseVisualStyleBackColor = false;
            this.buttonClear.Click += new System.EventHandler(this.buttonClear_Click);
            // 
            // buttonEriser
            // 
            this.buttonEriser.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.buttonEriser.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonEriser.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonEriser.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonEriser.Location = new System.Drawing.Point(128, 83);
            this.buttonEriser.Name = "buttonEriser";
            this.buttonEriser.Size = new System.Drawing.Size(112, 33);
            this.buttonEriser.TabIndex = 45;
            this.buttonEriser.Text = "Bs";
            this.HiddenInfo.SetToolTip(this.buttonEriser, "backspace input value");
            this.buttonEriser.UseVisualStyleBackColor = false;
            this.buttonEriser.Click += new System.EventHandler(this.buttonEriser_Click);
            // 
            // button7
            // 
            this.button7.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.button7.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button7.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button7.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button7.Location = new System.Drawing.Point(12, 122);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(72, 33);
            this.button7.TabIndex = 44;
            this.button7.Text = "7";
            this.button7.UseVisualStyleBackColor = false;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // button8
            // 
            this.button8.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.button8.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button8.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button8.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button8.Location = new System.Drawing.Point(90, 122);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(72, 33);
            this.button8.TabIndex = 43;
            this.button8.Text = "8";
            this.button8.UseVisualStyleBackColor = false;
            this.button8.Click += new System.EventHandler(this.button8_Click);
            // 
            // button9
            // 
            this.button9.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.button9.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button9.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button9.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button9.Location = new System.Drawing.Point(168, 122);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(72, 33);
            this.button9.TabIndex = 42;
            this.button9.Text = "9";
            this.button9.UseVisualStyleBackColor = false;
            this.button9.Click += new System.EventHandler(this.button9_Click);
            // 
            // button4
            // 
            this.button4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.button4.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button4.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button4.Location = new System.Drawing.Point(12, 161);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(72, 33);
            this.button4.TabIndex = 41;
            this.button4.Text = "4";
            this.button4.UseVisualStyleBackColor = false;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.button5.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button5.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button5.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button5.Location = new System.Drawing.Point(90, 161);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(72, 33);
            this.button5.TabIndex = 40;
            this.button5.Text = "5";
            this.button5.UseVisualStyleBackColor = false;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button6
            // 
            this.button6.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.button6.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button6.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button6.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button6.Location = new System.Drawing.Point(168, 161);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(72, 33);
            this.button6.TabIndex = 39;
            this.button6.Text = "6";
            this.button6.UseVisualStyleBackColor = false;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.button1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(12, 200);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(72, 33);
            this.button1.TabIndex = 38;
            this.button1.Text = "1";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.button2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button2.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.Location = new System.Drawing.Point(90, 200);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(72, 33);
            this.button2.TabIndex = 37;
            this.button2.Text = "2";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.button3.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button3.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.Location = new System.Drawing.Point(168, 200);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(72, 33);
            this.button3.TabIndex = 36;
            this.button3.Text = "3";
            this.button3.UseVisualStyleBackColor = false;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // buttonSum
            // 
            this.buttonSum.BackColor = System.Drawing.Color.Cyan;
            this.buttonSum.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonSum.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonSum.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonSum.Location = new System.Drawing.Point(91, 239);
            this.buttonSum.Name = "buttonSum";
            this.buttonSum.Size = new System.Drawing.Size(71, 33);
            this.buttonSum.TabIndex = 31;
            this.buttonSum.Text = "=";
            this.HiddenInfo.SetToolTip(this.buttonSum, "do operation and get sum ");
            this.buttonSum.UseVisualStyleBackColor = false;
            this.buttonSum.Click += new System.EventHandler(this.buttonSum_Click);
            // 
            // button0
            // 
            this.button0.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.button0.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button0.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button0.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button0.Location = new System.Drawing.Point(12, 239);
            this.button0.Name = "button0";
            this.button0.Size = new System.Drawing.Size(72, 33);
            this.button0.TabIndex = 29;
            this.button0.Text = "0";
            this.button0.UseVisualStyleBackColor = false;
            this.button0.Click += new System.EventHandler(this.button0_Click);
            // 
            // buttonA
            // 
            this.buttonA.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.buttonA.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonA.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonA.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonA.Location = new System.Drawing.Point(168, 239);
            this.buttonA.Name = "buttonA";
            this.buttonA.Size = new System.Drawing.Size(72, 33);
            this.buttonA.TabIndex = 49;
            this.buttonA.Text = "A";
            this.HiddenInfo.SetToolTip(this.buttonA, "hexadecimal characters");
            this.buttonA.UseVisualStyleBackColor = false;
            this.buttonA.Click += new System.EventHandler(this.button10_Click);
            // 
            // buttonB
            // 
            this.buttonB.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.buttonB.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonB.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonB.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonB.Location = new System.Drawing.Point(246, 83);
            this.buttonB.Name = "buttonB";
            this.buttonB.Size = new System.Drawing.Size(71, 33);
            this.buttonB.TabIndex = 48;
            this.buttonB.Text = "B";
            this.HiddenInfo.SetToolTip(this.buttonB, "hexadecimal characters");
            this.buttonB.UseVisualStyleBackColor = false;
            this.buttonB.Click += new System.EventHandler(this.button11_Click);
            // 
            // buttonC
            // 
            this.buttonC.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.buttonC.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonC.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonC.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonC.Location = new System.Drawing.Point(246, 122);
            this.buttonC.Name = "buttonC";
            this.buttonC.Size = new System.Drawing.Size(71, 33);
            this.buttonC.TabIndex = 47;
            this.buttonC.Text = "C";
            this.HiddenInfo.SetToolTip(this.buttonC, "hexadecimal characters");
            this.buttonC.UseVisualStyleBackColor = false;
            this.buttonC.Click += new System.EventHandler(this.button12_Click);
            // 
            // buttonD
            // 
            this.buttonD.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.buttonD.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonD.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonD.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonD.Location = new System.Drawing.Point(246, 161);
            this.buttonD.Name = "buttonD";
            this.buttonD.Size = new System.Drawing.Size(71, 33);
            this.buttonD.TabIndex = 51;
            this.buttonD.Text = "D";
            this.HiddenInfo.SetToolTip(this.buttonD, "hexadecimal characters");
            this.buttonD.UseVisualStyleBackColor = false;
            this.buttonD.Click += new System.EventHandler(this.buttonD_Click);
            // 
            // buttonE
            // 
            this.buttonE.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.buttonE.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonE.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonE.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonE.Location = new System.Drawing.Point(246, 200);
            this.buttonE.Name = "buttonE";
            this.buttonE.Size = new System.Drawing.Size(71, 33);
            this.buttonE.TabIndex = 50;
            this.buttonE.Text = "E";
            this.HiddenInfo.SetToolTip(this.buttonE, "hexadecimal characters");
            this.buttonE.UseVisualStyleBackColor = false;
            this.buttonE.Click += new System.EventHandler(this.button11_Click_1);
            // 
            // buttonF
            // 
            this.buttonF.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.buttonF.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonF.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonF.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonF.Location = new System.Drawing.Point(246, 239);
            this.buttonF.Name = "buttonF";
            this.buttonF.Size = new System.Drawing.Size(71, 33);
            this.buttonF.TabIndex = 53;
            this.buttonF.Text = "F";
            this.HiddenInfo.SetToolTip(this.buttonF, "hexadecimal characters");
            this.buttonF.UseVisualStyleBackColor = false;
            this.buttonF.Click += new System.EventHandler(this.button10_Click_1);
            // 
            // output
            // 
            this.output.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.output.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.output.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.output.ForeColor = System.Drawing.Color.White;
            this.output.Location = new System.Drawing.Point(12, 38);
            this.output.Name = "output";
            this.output.ReadOnly = true;
            this.output.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.output.Size = new System.Drawing.Size(304, 20);
            this.output.TabIndex = 58;
            this.output.Text = "output";
            this.HiddenInfo.SetToolTip(this.output, "output value is a decimal !\r\n");
            // 
            // OperationType
            // 
            this.OperationType.BackColor = System.Drawing.SystemColors.Menu;
            this.OperationType.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.OperationType.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.OperationType.FormattingEnabled = true;
            this.OperationType.ItemHeight = 20;
            this.OperationType.Items.AddRange(new object[] {
            "Decimal",
            "Binary",
            "HexaDecimal",
            "Octal"});
            this.OperationType.Location = new System.Drawing.Point(208, 12);
            this.OperationType.Name = "OperationType";
            this.OperationType.Size = new System.Drawing.Size(109, 20);
            this.OperationType.TabIndex = 61;
            this.HiddenInfo.SetToolTip(this.OperationType, "input value for operation\r\n");
            this.OperationType.SelectedIndexChanged += new System.EventHandler(this.OperationType_SelectedIndexChanged);
            // 
            // HiddenInfo
            // 
            this.HiddenInfo.AutoPopDelay = 5000;
            this.HiddenInfo.InitialDelay = 1000;
            this.HiddenInfo.IsBalloon = true;
            this.HiddenInfo.ReshowDelay = 100;
            this.HiddenInfo.ToolTipIcon = System.Windows.Forms.ToolTipIcon.Info;
            this.HiddenInfo.ToolTipTitle = "hint ! ";
            // 
            // ProgrammerCalculatorForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(31)))), ((int)(((byte)(45)))));
            this.ClientSize = new System.Drawing.Size(328, 284);
            this.Controls.Add(this.OperationType);
            this.Controls.Add(this.output);
            this.Controls.Add(this.buttonF);
            this.Controls.Add(this.buttonD);
            this.Controls.Add(this.buttonE);
            this.Controls.Add(this.buttonA);
            this.Controls.Add(this.buttonB);
            this.Controls.Add(this.buttonC);
            this.Controls.Add(this.buttonClear);
            this.Controls.Add(this.buttonEriser);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button8);
            this.Controls.Add(this.button9);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.buttonSum);
            this.Controls.Add(this.button0);
            this.Controls.Add(this.Input);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "ProgrammerCalculatorForm";
            this.Text = "Programmer Calculator ~ GUI";
            this.Load += new System.EventHandler(this.ProgrammerCalculatorForm_Load);
            this.Resize += new System.EventHandler(this.fixedSize);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox Input;
        private System.Windows.Forms.Button buttonClear;
        private System.Windows.Forms.Button buttonEriser;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Button button9;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button buttonSum;
        private System.Windows.Forms.Button button0;
        private System.Windows.Forms.Button buttonA;
        private System.Windows.Forms.Button buttonB;
        private System.Windows.Forms.Button buttonC;
        private System.Windows.Forms.Button buttonD;
        private System.Windows.Forms.Button buttonE;
        private System.Windows.Forms.Button buttonF;
        private System.Windows.Forms.TextBox output;
        private System.Windows.Forms.ListBox OperationType;
        private System.Windows.Forms.ToolTip HiddenInfo;
    }
}