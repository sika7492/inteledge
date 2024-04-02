namespace dbConNet
{
    partial class dbCon
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
            bnCofirm = new Button();
            tbCofirm = new TextBox();
            bnRemove = new Button();
            ckbOpt10 = new CheckBox();
            ckbOpt20 = new CheckBox();
            optFruit = new Label();
            groupBox1 = new GroupBox();
            optColor = new Label();
            rbBlue = new RadioButton();
            rbGreen = new RadioButton();
            rbRed = new RadioButton();
            groupBox2 = new GroupBox();
            optLoc = new Label();
            rbSp = new RadioButton();
            rbEq = new RadioButton();
            rbNp = new RadioButton();
            cmbDv = new ComboBox();
            lbBtnCnt = new ListBox();
            tbCmbTxt = new TextBox();
            tbBtnCnt = new TextBox();
            label1 = new Label();
            tbKey = new TextBox();
            cmbDic = new ComboBox();
            label2 = new Label();
            lblDate = new Label();
            timer1 = new System.Windows.Forms.Timer(components);
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            SuspendLayout();
            // 
            // bnCofirm
            // 
            bnCofirm.Location = new Point(48, 37);
            bnCofirm.Name = "bnCofirm";
            bnCofirm.Size = new Size(95, 45);
            bnCofirm.TabIndex = 0;
            bnCofirm.Text = "Click 확인";
            bnCofirm.UseVisualStyleBackColor = true;
            bnCofirm.Click += bnConfirm_Click;
            // 
            // tbCofirm
            // 
            tbCofirm.Location = new Point(250, 37);
            tbCofirm.Multiline = true;
            tbCofirm.Name = "tbCofirm";
            tbCofirm.Size = new Size(664, 45);
            tbCofirm.TabIndex = 1;
            // 
            // bnRemove
            // 
            bnRemove.Location = new Point(149, 37);
            bnRemove.Name = "bnRemove";
            bnRemove.Size = new Size(95, 45);
            bnRemove.TabIndex = 2;
            bnRemove.Text = "텍스트 지우기";
            bnRemove.UseVisualStyleBackColor = true;
            bnRemove.Click += bnRemove_Click;
            // 
            // ckbOpt10
            // 
            ckbOpt10.AutoSize = true;
            ckbOpt10.Font = new Font("돋움체", 14.25F);
            ckbOpt10.Location = new Point(59, 155);
            ckbOpt10.Name = "ckbOpt10";
            ckbOpt10.Size = new Size(68, 23);
            ckbOpt10.TabIndex = 3;
            ckbOpt10.Text = "사과";
            ckbOpt10.UseVisualStyleBackColor = true;
            ckbOpt10.CheckedChanged += ckbOpt10_CheckedChanged;
            // 
            // ckbOpt20
            // 
            ckbOpt20.AutoSize = true;
            ckbOpt20.Font = new Font("돋움체", 14.25F);
            ckbOpt20.Location = new Point(59, 184);
            ckbOpt20.Name = "ckbOpt20";
            ckbOpt20.Size = new Size(68, 23);
            ckbOpt20.TabIndex = 4;
            ckbOpt20.Text = "딸기";
            ckbOpt20.UseVisualStyleBackColor = true;
            ckbOpt20.CheckedChanged += ckbOpt20_CheckedChanged;
            // 
            // optFruit
            // 
            optFruit.AutoSize = true;
            optFruit.Font = new Font("돋움체", 14.25F);
            optFruit.Location = new Point(175, 159);
            optFruit.Name = "optFruit";
            optFruit.Size = new Size(0, 19);
            optFruit.TabIndex = 7;
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(optColor);
            groupBox1.Controls.Add(rbBlue);
            groupBox1.Controls.Add(rbGreen);
            groupBox1.Controls.Add(rbRed);
            groupBox1.Location = new Point(36, 265);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(227, 136);
            groupBox1.TabIndex = 14;
            groupBox1.TabStop = false;
            groupBox1.Text = "Color";
            // 
            // optColor
            // 
            optColor.AutoSize = true;
            optColor.Font = new Font("돋움체", 14.25F);
            optColor.Location = new Point(127, 23);
            optColor.Name = "optColor";
            optColor.Size = new Size(0, 19);
            optColor.TabIndex = 14;
            // 
            // rbBlue
            // 
            rbBlue.AutoSize = true;
            rbBlue.Font = new Font("돋움체", 14.25F);
            rbBlue.Location = new Point(15, 102);
            rbBlue.Name = "rbBlue";
            rbBlue.Size = new Size(67, 23);
            rbBlue.TabIndex = 13;
            rbBlue.TabStop = true;
            rbBlue.Text = "Blue";
            rbBlue.UseVisualStyleBackColor = true;
            // 
            // rbGreen
            // 
            rbGreen.AutoSize = true;
            rbGreen.Font = new Font("돋움체", 14.25F);
            rbGreen.Location = new Point(15, 63);
            rbGreen.Name = "rbGreen";
            rbGreen.Size = new Size(77, 23);
            rbGreen.TabIndex = 11;
            rbGreen.TabStop = true;
            rbGreen.Text = "Green";
            rbGreen.UseVisualStyleBackColor = true;
            // 
            // rbRed
            // 
            rbRed.AutoSize = true;
            rbRed.Font = new Font("돋움체", 14.25F);
            rbRed.Location = new Point(15, 23);
            rbRed.Name = "rbRed";
            rbRed.Size = new Size(57, 23);
            rbRed.TabIndex = 10;
            rbRed.TabStop = true;
            rbRed.Text = "Red";
            rbRed.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(optLoc);
            groupBox2.Controls.Add(rbSp);
            groupBox2.Controls.Add(rbEq);
            groupBox2.Controls.Add(rbNp);
            groupBox2.Location = new Point(279, 265);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(226, 136);
            groupBox2.TabIndex = 15;
            groupBox2.TabStop = false;
            groupBox2.Text = "Location";
            // 
            // optLoc
            // 
            optLoc.AutoSize = true;
            optLoc.Font = new Font("돋움체", 14.25F);
            optLoc.Location = new Point(158, 27);
            optLoc.Name = "optLoc";
            optLoc.Size = new Size(0, 19);
            optLoc.TabIndex = 18;
            // 
            // rbSp
            // 
            rbSp.AutoSize = true;
            rbSp.Font = new Font("돋움체", 14.25F);
            rbSp.Location = new Point(14, 102);
            rbSp.Name = "rbSp";
            rbSp.Size = new Size(127, 23);
            rbSp.TabIndex = 17;
            rbSp.TabStop = true;
            rbSp.Text = "South Pole";
            rbSp.UseVisualStyleBackColor = true;
            // 
            // rbEq
            // 
            rbEq.AutoSize = true;
            rbEq.Font = new Font("돋움체", 14.25F);
            rbEq.Location = new Point(14, 63);
            rbEq.Name = "rbEq";
            rbEq.Size = new Size(97, 23);
            rbEq.TabIndex = 15;
            rbEq.TabStop = true;
            rbEq.Text = "Equator";
            rbEq.UseVisualStyleBackColor = true;
            // 
            // rbNp
            // 
            rbNp.AutoSize = true;
            rbNp.Font = new Font("돋움체", 14.25F);
            rbNp.Location = new Point(14, 23);
            rbNp.Name = "rbNp";
            rbNp.Size = new Size(127, 23);
            rbNp.TabIndex = 14;
            rbNp.TabStop = true;
            rbNp.Text = "North Pole";
            rbNp.UseVisualStyleBackColor = true;
            // 
            // cmbDv
            // 
            cmbDv.Font = new Font("맑은 고딕", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 129);
            cmbDv.FormattingEnabled = true;
            cmbDv.Items.AddRange(new object[] { "데스크탑", "노트북", "패드" });
            cmbDv.Location = new Point(688, 145);
            cmbDv.Name = "cmbDv";
            cmbDv.Size = new Size(110, 33);
            cmbDv.TabIndex = 16;
            cmbDv.SelectedIndexChanged += cmbDv_SelectedIndexChanged;
            // 
            // lbBtnCnt
            // 
            lbBtnCnt.Font = new Font("맑은 고딕", 12F, FontStyle.Regular, GraphicsUnit.Point, 129);
            lbBtnCnt.FormattingEnabled = true;
            lbBtnCnt.ItemHeight = 21;
            lbBtnCnt.Items.AddRange(new object[] { "마우스 3", "키보드 101", "모니터 5", "리모트 30", "자동차 10", "휴대폰 3" });
            lbBtnCnt.Location = new Point(688, 265);
            lbBtnCnt.Name = "lbBtnCnt";
            lbBtnCnt.Size = new Size(226, 88);
            lbBtnCnt.TabIndex = 17;
            lbBtnCnt.SelectedIndexChanged += lbBtnCnt_SelectedIndexChanged;
            // 
            // tbCmbTxt
            // 
            tbCmbTxt.BackColor = SystemColors.Control;
            tbCmbTxt.BorderStyle = BorderStyle.FixedSingle;
            tbCmbTxt.Font = new Font("맑은 고딕", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 129);
            tbCmbTxt.Location = new Point(804, 145);
            tbCmbTxt.Name = "tbCmbTxt";
            tbCmbTxt.Size = new Size(110, 33);
            tbCmbTxt.TabIndex = 18;
            // 
            // tbBtnCnt
            // 
            tbBtnCnt.BackColor = SystemColors.Control;
            tbBtnCnt.BorderStyle = BorderStyle.FixedSingle;
            tbBtnCnt.Font = new Font("맑은 고딕", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 129);
            tbBtnCnt.Location = new Point(804, 367);
            tbBtnCnt.Name = "tbBtnCnt";
            tbBtnCnt.Size = new Size(110, 33);
            tbBtnCnt.TabIndex = 19;
            tbBtnCnt.TextAlign = HorizontalAlignment.Center;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("맑은 고딕", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 129);
            label1.Location = new Point(691, 369);
            label1.Name = "label1";
            label1.Size = new Size(104, 30);
            label1.TabIndex = 20;
            label1.Text = "버튼 갯수";
            // 
            // tbKey
            // 
            tbKey.BackColor = SystemColors.Control;
            tbKey.BorderStyle = BorderStyle.FixedSingle;
            tbKey.Font = new Font("맑은 고딕", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 129);
            tbKey.Location = new Point(469, 145);
            tbKey.Name = "tbKey";
            tbKey.Size = new Size(151, 33);
            tbKey.TabIndex = 22;
            tbKey.TextAlign = HorizontalAlignment.Right;
            // 
            // cmbDic
            // 
            cmbDic.Font = new Font("맑은 고딕", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 129);
            cmbDic.FormattingEnabled = true;
            cmbDic.Location = new Point(280, 145);
            cmbDic.Name = "cmbDic";
            cmbDic.Size = new Size(172, 33);
            cmbDic.TabIndex = 21;
            cmbDic.SelectedIndexChanged += cmbDic_SelectedIndexChanged;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("맑은 고딕", 27.75F);
            label2.Location = new Point(36, 447);
            label2.Name = "label2";
            label2.Size = new Size(130, 50);
            label2.TabIndex = 23;
            label2.Text = "시간 : ";
            // 
            // lblDate
            // 
            lblDate.AutoSize = true;
            lblDate.Font = new Font("맑은 고딕", 27.75F);
            lblDate.ForeColor = Color.Olive;
            lblDate.Location = new Point(199, 447);
            lblDate.Name = "lblDate";
            lblDate.Size = new Size(0, 50);
            lblDate.TabIndex = 24;
            // 
            // timer1
            // 
            timer1.Interval = 1000;
            timer1.Tick += timer1_Tick;
            // 
            // dbCon
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(973, 571);
            Controls.Add(lblDate);
            Controls.Add(label2);
            Controls.Add(tbKey);
            Controls.Add(cmbDic);
            Controls.Add(label1);
            Controls.Add(tbBtnCnt);
            Controls.Add(tbCmbTxt);
            Controls.Add(lbBtnCnt);
            Controls.Add(cmbDv);
            Controls.Add(optFruit);
            Controls.Add(ckbOpt20);
            Controls.Add(ckbOpt10);
            Controls.Add(bnRemove);
            Controls.Add(tbCofirm);
            Controls.Add(bnCofirm);
            Controls.Add(groupBox1);
            Controls.Add(groupBox2);
            Name = "dbCon";
            Text = "DB 확인";
            Load += dbCon_Load;
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button bnCofirm;
        private TextBox tbCofirm;
        private Button bnRemove;
        private CheckBox ckbOpt10;
        private CheckBox ckbOpt20;
        private Label optFruit;
        private GroupBox groupBox1;
        private GroupBox groupBox2;
        private RadioButton rbBlue;
        private RadioButton rbGreen;
        private RadioButton rbRed;
        private RadioButton rbSp;
        private RadioButton rbEq;
        private RadioButton rbNp;
        private Label optColor;
        private Label optLoc;
        private ComboBox cmbDv;
        private ListBox lbBtnCnt;
        private TextBox tbCmbTxt;
        private TextBox tbBtnCnt;
        private Label label1;
        private TextBox tbKey;
        private ComboBox cmbDic;
        private Label label2;
        private Label lblDate;
        private System.Windows.Forms.Timer timer1;
    }
}