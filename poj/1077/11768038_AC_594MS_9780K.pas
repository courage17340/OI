{poj 1077}
type
  pic=array[1..9] of longint;
  rec=record sta:pic;father,p:longint;ch:char;end;
var
  a,ans:pic;
  b:array[1..400000] of rec;
  v:array[1..400000] of boolean;
  c,fun:array[0..9] of longint;
  s:string;
  i,j,t,p:longint;
function f(a:pic):longint;
var
  i,j:longint;
begin
  f:=0;
  fillchar(c,sizeof(c),0);
  for i:=1 to 8 do
    for j:=i+1 to 9 do
      if a[i]>a[j] then inc(c[i]);
  for i:=1 to 8 do f:=f+c[i]*fun[9-i];
  inc(f);
end;

procedure print(x:longint);
begin
  s:='';
  while x<>1 do
    begin
      s:=b[x].ch+s;
      x:=b[x].father;
    end;
  writeln(s);
  halt;
end;

begin
  for i:=1 to 9 do ans[i]:=i;
  fun[1]:=1;
  for i:=2 to 9 do fun[i]:=fun[i-1]*i;
  readln(s);
  s[pos('x',s)]:='9';
  for i:=1 to 9 do
    begin
      while s[1]=' ' do delete(s,1,1);
      a[i]:=ord(s[1])-48;
      if a[i]=9 then b[1].p:=i;
      delete(s,1,1);
    end;
  i:=1;j:=1;
  b[1].sta:=a;
  b[1].ch:=' ';
  fillchar(v,sizeof(v),true);
  v[f(b[1].sta)]:=false;
  while i<j+1 do
    begin
      if b[i].p>3 then
        begin
          p:=b[i].p;
          a:=b[i].sta;t:=a[p];a[p]:=a[p-3];a[p-3]:=t;
          if v[f(a)] then
            begin
              v[f(a)]:=false;
              inc(j);
              b[j].father:=i;
              b[j].sta:=a;
              b[j].ch:='u';
              b[j].p:=b[i].p-3;
              if f(a)=f(ans) then print(j);
            end;
        end;
      if b[i].p<7 then
        begin
          p:=b[i].p;
          a:=b[i].sta;t:=a[p];a[p]:=a[p+3];a[p+3]:=t;
          if v[f(a)] then
            begin
              v[f(a)]:=false;
              inc(j);
              b[j].father:=i;
              b[j].sta:=a;
              b[j].ch:='d';
              b[j].p:=b[i].p+3;
              if f(a)=f(ans) then print(j);
            end;
        end;
      if b[i].p mod 3<>1 then
        begin
          p:=b[i].p;
          a:=b[i].sta;t:=a[p];a[p]:=a[p-1];a[p-1]:=t;
          if v[f(a)] then
            begin
              v[f(a)]:=false;
              inc(j);
              b[j].father:=i;
              b[j].sta:=a;
              b[j].ch:='l';
              b[j].p:=b[i].p-1;
              if f(a)=f(ans) then print(j);
            end;
        end;
      if b[i].p mod 3<>0 then
        begin
          p:=b[i].p;
          a:=b[i].sta;t:=a[p];a[p]:=a[p+1];a[p+1]:=t;
          if v[f(a)] then
            begin
              v[f(a)]:=false;
              inc(j);
              b[j].father:=i;
              b[j].sta:=a;
              b[j].ch:='r';
              b[j].p:=b[i].p+1;
              if f(a)=f(ans) then print(j);
            end;
        end;
      inc(i);
    end;
  writeln('unsolvable');
end.