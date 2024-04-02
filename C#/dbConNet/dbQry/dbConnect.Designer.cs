namespace dbQry
{
    partial class dbConnect
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
            bnConConfirm = new Button();
            bnCountQry = new Button();
            bnQryText = new Button();
            tbMsg = new TextBox();
            SuspendLayout();
            // 
            // bnConConfirm
            // 
            bnConConfirm.Font = new Font("맑은 고딕", 12F);
            bnConConfirm.Location = new Point(27, 19);
            bnConConfirm.Name = "bnConConfirm";
            bnConConfirm.Size = new Size(91, 34);
            bnConConfirm.TabIndex = 0;
            bnConConfirm.Text = "연결확인";
            bnConConfirm.UseVisualStyleBackColor = true;
            bnConConfirm.Click += button1_Click;
            // 
            // bnCountQry
            // 
            bnCountQry.Font = new Font("맑은 고딕", 12F);
            bnCountQry.Location = new Point(27, 59);
            bnCountQry.Name = "bnCountQry";
            bnCountQry.Size = new Size(91, 34);
            bnCountQry.TabIndex = 1;
            bnCountQry.Text = "조회 건수";
            bnCountQry.UseVisualStyleBackColor = true;
            bnCountQry.Click += button2_Click;
            // 
            // bnQryText
            // 
            bnQryText.Font = new Font("맑은 고딕", 12F);
            bnQryText.Location = new Point(27, 134);
            bnQryText.Name = "bnQryText";
            bnQryText.Size = new Size(91, 34);
            bnQryText.TabIndex = 2;
            bnQryText.Text = "쿼리 조회";
            bnQryText.UseVisualStyleBackColor = true;
            bnQryText.Click += button3_Click;
            // 
            // tbMsg
            // 
            tbMsg.Font = new Font("맑은 고딕", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 129);
            tbMsg.Location = new Point(148, 19);
            tbMsg.Multiline = true;
            tbMsg.Name = "tbMsg";
            tbMsg.ScrollBars = ScrollBars.Vertical;
            tbMsg.Size = new Size(621, 410);
            tbMsg.TabIndex = 3;
            // 
            // dbConnect
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(tbMsg);
            Controls.Add(bnQryText);
            Controls.Add(bnCountQry);
            Controls.Add(bnConConfirm);
            Name = "dbConnect";
            Text = "연결해 봅시다.";
            Load += dbConnect_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button bnConConfirm;
        private Button bnCountQry;
        private Button bnQryText;
        private TextBox tbMsg;
    }
}