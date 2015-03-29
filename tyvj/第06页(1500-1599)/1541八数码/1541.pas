type
  pic=array[1..9] of longint;
  rec=record sta:pic;step,p:longint;end;
var
  a:pic;
  ans:pic=(1,2,3,8,9,4,7,6,5);
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
  writeln(x);
  halt;
end;

begin
  fun[1]:=1;
  for i:=2 to 9 do fun[i]:=fun[i-1]*i;
  readln(s);
  s[pos('0',s)]:='9';
  for i:=1 to 9 do a[i]:=ord(s[i])-48;
  i:=1;j:=1;
  b[1].sta:=a;
  b[1].step:=0;
  b[1].p:=pos('9',s);
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
              b[j].sta:=a;
              b[j].p:=b[i].p-3;
			  b[j].step:=b[i].step+1;
              if f(a)=f(ans) then print(b[j].step);
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
              b[j].sta:=a;
              b[j].p:=b[i].p+3;
			  b[j].step:=b[i].step+1;
              if f(a)=f(ans) then print(b[j].step);
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
              b[j].sta:=a;
              b[j].p:=b[i].p-1;
			  b[j].step:=b[i].step+1;
              if f(a)=f(ans) then print(b[j].step);
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
              b[j].sta:=a;
              b[j].p:=b[i].p+1;
			  b[j].step:=b[i].step+1;
              if f(a)=f(ans) then print(b[j].step);
            end;
        end;
      inc(i);
    end;
end.