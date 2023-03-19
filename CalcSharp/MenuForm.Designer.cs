﻿namespace Calculator___GUI
{
    partial class MainForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.normalCalculator = new System.Windows.Forms.Button();
            this.programmerCalculator = new System.Windows.Forms.Button();
            this.about = new System.Windows.Forms.Button();
            this.HiddenInfoMain = new System.Windows.Forms.ToolTip(this.components);
            this.SuspendLayout();
            // 
            // normalCalculator
            // 
            this.normalCalculator.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(8)))), ((int)(((byte)(76)))), ((int)(((byte)(97)))));
            this.normalCalculator.Cursor = System.Windows.Forms.Cursors.Hand;
            this.normalCalculator.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.normalCalculator.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.normalCalculator.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.normalCalculator.Location = new System.Drawing.Point(12, 12);
            this.normalCalculator.Name = "normalCalculator";
            this.normalCalculator.Size = new System.Drawing.Size(133, 87);
            this.normalCalculator.TabIndex = 0;
            this.normalCalculator.Text = "NORMAL\r\nMODE";
            this.HiddenInfoMain.SetToolTip(this.normalCalculator, "normal calculator");
            this.normalCalculator.UseVisualStyleBackColor = false;
            this.normalCalculator.Click += new System.EventHandler(this.button1_Click);
            // 
            // programmerCalculator
            // 
            this.programmerCalculator.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(121)))), ((int)(((byte)(145)))));
            this.programmerCalculator.Cursor = System.Windows.Forms.Cursors.Hand;
            this.programmerCalculator.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.programmerCalculator.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.programmerCalculator.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.programmerCalculator.Location = new System.Drawing.Point(12, 109);
            this.programmerCalculator.Name = "programmerCalculator";
            this.programmerCalculator.Size = new System.Drawing.Size(236, 87);
            this.programmerCalculator.TabIndex = 1;
            this.programmerCalculator.Text = "PROGRAMMER\r\nMODE";
            this.HiddenInfoMain.SetToolTip(this.programmerCalculator, "programmer calculator");
            this.programmerCalculator.UseVisualStyleBackColor = false;
            this.programmerCalculator.Click += new System.EventHandler(this.programmerCalculator_Click);
            // 
            // about
            // 
            this.about.BackColor = System.Drawing.Color.Transparent;
            this.about.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("about.BackgroundImage")));
            this.about.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.about.Cursor = System.Windows.Forms.Cursors.Hand;
            this.about.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.about.ForeColor = System.Drawing.Color.White;
            this.about.Location = new System.Drawing.Point(151, 12);
            this.about.Name = "about";
            this.about.Size = new System.Drawing.Size(97, 87);
            this.about.TabIndex = 2;
            this.HiddenInfoMain.SetToolTip(this.about, "about me !");
            this.about.UseVisualStyleBackColor = false;
            this.about.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // HiddenInfoMain
            // 
            this.HiddenInfoMain.AutoPopDelay = 5000;
            this.HiddenInfoMain.InitialDelay = 1000;
            this.HiddenInfoMain.IsBalloon = true;
            this.HiddenInfoMain.ReshowDelay = 100;
            this.HiddenInfoMain.ToolTipIcon = System.Windows.Forms.ToolTipIcon.Info;
            this.HiddenInfoMain.ToolTipTitle = "Info";
            this.HiddenInfoMain.Popup += new System.Windows.Forms.PopupEventHandler(this.HiddenInfoMain_Popup);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(31)))), ((int)(((byte)(45)))));
            this.ClientSize = new System.Drawing.Size(260, 207);
            this.Controls.Add(this.about);
            this.Controls.Add(this.programmerCalculator);
            this.Controls.Add(this.normalCalculator);
            this.ForeColor = System.Drawing.Color.Lime;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.Text = "CalcSharp";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Resize += new System.EventHandler(this.fixedSize);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button normalCalculator;
        private System.Windows.Forms.Button programmerCalculator;
        private System.Windows.Forms.Button about;
        private System.Windows.Forms.ToolTip HiddenInfoMain;
    }
}

