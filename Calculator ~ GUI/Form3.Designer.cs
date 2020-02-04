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
            this.name = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // aboutText
            // 
            this.aboutText.AutoSize = true;
            this.aboutText.BackColor = System.Drawing.Color.Transparent;
            this.aboutText.Font = new System.Drawing.Font("Miriam CLM", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.aboutText.ForeColor = System.Drawing.Color.White;
            this.aboutText.Location = new System.Drawing.Point(11, 47);
            this.aboutText.Name = "aboutText";
            this.aboutText.Size = new System.Drawing.Size(227, 80);
            this.aboutText.TabIndex = 1;
            this.aboutText.Text = "version 1 Free & Open-Source for you \r\ncan go to the project from github \r\nbutton" +
    " & get your fork \r\n\r\n\r\n";
            // 
            // githubButton
            // 
            this.githubButton.BackColor = System.Drawing.Color.White;
            this.githubButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.githubButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.githubButton.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.githubButton.Font = new System.Drawing.Font("Miriam CLM", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.githubButton.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.githubButton.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.githubButton.Location = new System.Drawing.Point(14, 108);
            this.githubButton.Name = "githubButton";
            this.githubButton.Size = new System.Drawing.Size(224, 47);
            this.githubButton.TabIndex = 2;
            this.githubButton.Text = "Github";
            this.githubButton.UseVisualStyleBackColor = false;
            this.githubButton.Click += new System.EventHandler(this.githubButton_Click);
            // 
            // name
            // 
            this.name.AutoSize = true;
            this.name.BackColor = System.Drawing.Color.Transparent;
            this.name.Font = new System.Drawing.Font("DejaVu Sans", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.name.ForeColor = System.Drawing.Color.LawnGreen;
            this.name.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.name.Location = new System.Drawing.Point(11, 26);
            this.name.Name = "name";
            this.name.Size = new System.Drawing.Size(106, 15);
            this.name.TabIndex = 3;
            this.name.Text = "OUCHANE_CC";
            // 
            // aboutForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::Calculator___GUI.Properties.Resources.back;
            this.ClientSize = new System.Drawing.Size(253, 170);
            this.Controls.Add(this.name);
            this.Controls.Add(this.githubButton);
            this.Controls.Add(this.aboutText);
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
        private System.Windows.Forms.Label name;
    }
}