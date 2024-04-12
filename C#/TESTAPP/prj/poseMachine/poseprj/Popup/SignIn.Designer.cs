namespace poseprj.Popup
{
    partial class SignIn
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
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SignIn));
            pb = new PictureBox();
            textBox1 = new TextBox();
            txtuser = new TextBox();
            txtpwd = new TextBox();
            ckbsave = new CheckBox();
            bnlogin = new Button();
            bncancel = new Button();
            txdate = new TextBox();
            timer1 = new System.Windows.Forms.Timer(components);
            ((System.ComponentModel.ISupportInitialize)pb).BeginInit();
            SuspendLayout();
            // 
            // pb
            // 
            pb.Image = Properties.Resources.make;
            pb.InitialImage = (Image)resources.GetObject("pb.InitialImage");
            pb.Location = new Point(16, 29);
            pb.Name = "pb";
            pb.Size = new Size(48, 48);
            pb.SizeMode = PictureBoxSizeMode.StretchImage;
            pb.TabIndex = 0;
            pb.TabStop = false;
            // 
            // textBox1
            // 
            textBox1.BackColor = SystemColors.Control;
            textBox1.BorderStyle = BorderStyle.None;
            textBox1.Font = new Font("맑은 고딕", 27.75F, FontStyle.Regular, GraphicsUnit.Point, 129);
            textBox1.Location = new Point(70, 29);
            textBox1.Multiline = true;
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(291, 55);
            textBox1.TabIndex = 900;
            textBox1.Text = "테스트 프로젝트";
            // 
            // txtuser
            // 
            txtuser.Location = new Point(16, 140);
            txtuser.Name = "txtuser";
            txtuser.PlaceholderText = "사용자 아이디를 입력하세요.";
            txtuser.Size = new Size(242, 26);
            txtuser.TabIndex = 4;
            txtuser.KeyDown += txtpwd_KeyDown;
            // 
            // txtpwd
            // 
            txtpwd.Location = new Point(16, 187);
            txtpwd.Name = "txtpwd";
            txtpwd.PasswordChar = '*';
            txtpwd.PlaceholderText = "비밀번호를 입력하세요.";
            txtpwd.Size = new Size(306, 26);
            txtpwd.TabIndex = 5;
            txtpwd.KeyDown += txtpwd_KeyDown;
            // 
            // ckbsave
            // 
            ckbsave.AutoSize = true;
            ckbsave.Location = new Point(264, 140);
            ckbsave.Name = "ckbsave";
            ckbsave.Size = new Size(58, 20);
            ckbsave.TabIndex = 6;
            ckbsave.Text = "저장";
            ckbsave.UseVisualStyleBackColor = true;
            ckbsave.CheckedChanged += ckbsave_CheckedChanged;
            // 
            // bnlogin
            // 
            bnlogin.Location = new Point(16, 420);
            bnlogin.Name = "bnlogin";
            bnlogin.Size = new Size(133, 86);
            bnlogin.TabIndex = 7;
            bnlogin.Text = "로그인";
            bnlogin.UseVisualStyleBackColor = true;
            bnlogin.Click += bnlogin_Click;
            // 
            // bncancel
            // 
            bncancel.Location = new Point(189, 469);
            bncancel.Name = "bncancel";
            bncancel.Size = new Size(133, 37);
            bncancel.TabIndex = 10;
            bncancel.Text = "CANCEL";
            bncancel.UseVisualStyleBackColor = true;
            // 
            // txdate
            // 
            txdate.BackColor = SystemColors.Control;
            txdate.BorderStyle = BorderStyle.None;
            txdate.Font = new Font("돋움", 28F);
            txdate.ForeColor = Color.Maroon;
            txdate.Location = new Point(16, 243);
            txdate.Multiline = true;
            txdate.Name = "txdate";
            txdate.Size = new Size(313, 118);
            txdate.TabIndex = 910;
            txdate.Text = "2024년 4월 12일 \r\n\r\n11시 10분 52초\r\n";
            txdate.TextAlign = HorizontalAlignment.Center;
            // 
            // timer1
            // 
            timer1.Interval = 1000;
            timer1.Tick += timer1_Tick;
            // 
            // SignIn
            // 
            AutoScaleDimensions = new SizeF(9F, 16F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(384, 561);
            Controls.Add(txdate);
            Controls.Add(bncancel);
            Controls.Add(bnlogin);
            Controls.Add(ckbsave);
            Controls.Add(txtpwd);
            Controls.Add(txtuser);
            Controls.Add(textBox1);
            Controls.Add(pb);
            Font = new Font("돋움", 12F, FontStyle.Regular, GraphicsUnit.Point, 129);
            FormBorderStyle = FormBorderStyle.None;
            Margin = new Padding(4, 3, 4, 3);
            MaximizeBox = false;
            MinimizeBox = false;
            Name = "SignIn";
            Text = "SignIn";
            Load += SignIn_Load;
            ((System.ComponentModel.ISupportInitialize)pb).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private PictureBox pb;
        private TextBox textBox1;
        private TextBox txtuser;
        private TextBox txtpwd;
        private CheckBox ckbsave;
        private Button bnlogin;
        private Button bncancel;
        private TextBox txdate;
        private System.Windows.Forms.Timer timer1;
    }
}