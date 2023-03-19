namespace Calculator___GUI
{
    partial class aboutForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(aboutForm));
            this.aboutText = new System.Windows.Forms.Label();
            this.githubButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // aboutText
            // 
            this.aboutText.AutoSize = true;
            this.aboutText.BackColor = System.Drawing.Color.Transparent;
            this.aboutText.Font = new System.Drawing.Font("18 Khebrat Musamim", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.aboutText.ForeColor = System.Drawing.Color.Black;
            this.aboutText.Location = new System.Drawing.Point(6, 22);
            this.aboutText.Name = "aboutText";
            this.aboutText.Size = new System.Drawing.Size(289, 56);
            this.aboutText.TabIndex = 1;
            this.aboutText.Text = "Open-Source Calculator for educational \r\npurposes you can check the Source-Code\r\n" +
    "";
            this.aboutText.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.aboutText.Click += new System.EventHandler(this.aboutText_Click);
            // 
            // githubButton
            // 
            this.githubButton.BackColor = System.Drawing.Color.Teal;
            this.githubButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.githubButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.githubButton.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.githubButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.githubButton.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.githubButton.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.githubButton.Location = new System.Drawing.Point(34, 90);
            this.githubButton.Name = "githubButton";
            this.githubButton.Size = new System.Drawing.Size(224, 47);
            this.githubButton.TabIndex = 2;
            this.githubButton.Text = "Github";
            this.githubButton.UseVisualStyleBackColor = false;
            this.githubButton.Click += new System.EventHandler(this.githubButton_Click);
            // 
            // aboutForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(298, 149);
            this.Controls.Add(this.githubButton);
            this.Controls.Add(this.aboutText);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "aboutForm";
            this.Text = "About";
            this.Resize += new System.EventHandler(this.aboutForm_Resize);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label aboutText;
        private System.Windows.Forms.Button githubButton;
    }
}