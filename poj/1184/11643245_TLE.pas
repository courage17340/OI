type
  rec=record
        x,r,step:longint;
      end;
var
  a:array[0..1000000,1..6] of boolean;
  b:array[1..6000100] of rec;
  m1,m2,j,k,p,q:longint;
  ans:longint;
function swap0(x,p:longint):longint;
var
  s:string;
  ch:char;
begin
  str(x,s);while length(s)<6 do s:='0'+s;
  ch:=s[p];s[p]:=s[1];s[1]:=ch;
  val(s,x);
  exit(x);
end;

function swap1(x,p:longint):longint;
var
  s:string;
  ch:char;
begin
  str(x,s);while length(s)<6 do s:='0'+s;
  ch:=s[p];s[p]:=s[6];s[6]:=ch;
  val(s,x);
  exit(x);
end;

function up(x,p:longint):longint;
var
  s:string;
  ch:char;
begin
  str(x,s);while length(s)<6 do s:='0'+s;
  ch:=s[p];
  if ch<>'9' then s[p]:=chr(ord(ch)+1);
  val(s,x);
  exit(x);
end;

function down(x,p:longint):longint;
var
  s:string;
  ch:char;
begin
  str(x,s);while length(s)<6 do s:='0'+s;
  ch:=s[p];
  if ch<>'0' then s[p]:=chr(ord(ch)-1);
  val(s,x);
  exit(x);
end;

function left(p:longint):longint;
begin
  if p>1 then dec(p);
  exit(p);
end;

function right(p:longint):longint;
begin
  if p<6 then inc(p);
  exit(p);
end;

begin
  readln(m1,m2);
  fillchar(a,sizeof(a),true);
  ans:=0;
  p:=0;q:=1;
  b[1].x:=m1;
  b[1].r:=1;
  b[1].step:=0;
  a[m1,1]:=false;
  if m1=m2 then begin writeln(0);halt;end;
  while true do
    begin
      inc(p);
      if b[p].x=m2 then
        begin
          ans:=b[p].step;
          break;
        end;
      j:=b[p].x;
      k:=b[p].r;
      if a[swap0(j,k),k] then begin a[swap0(j,k),k]:=false;inc(q);b[q].x:=swap0(j,k);b[q].r:=k;b[q].step:=b[p].step+1;end;
      if a[swap1(j,k),k] then begin a[swap1(j,k),k]:=false;inc(q);b[q].x:=swap1(j,k);b[q].r:=k;b[q].step:=b[p].step+1;end;
      if a[up(j,k),k] then begin a[up(j,k),k]:=false;inc(q);b[q].x:=up(j,k);b[q].r:=k;b[q].step:=b[p].step+1;end;
      if a[down(j,k),k] then begin a[down(j,k),k]:=false;inc(q);b[q].x:=down(j,k);b[q].r:=k;b[q].step:=b[p].step+1;end;
  //    if a[j,left(k)] then begin a[j,left(k)]:=false;inc(q);b[q].x:=j;b[q].r:=left(k);b[q].step:=b[p].step+1;end;
      if a[j,right(k)] then begin a[j,right(k)]:=false;inc(q);b[q].x:=j;b[q].r:=right(k);b[q].step:=b[p].step+1;end;
    end;
  writeln(ans);
end.