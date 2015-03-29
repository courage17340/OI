var
  s,s1:string;
  a:array[0..20] of longint;
  b:array[0..20] of char;
  i,j,n:longint;
function mi(a,b:longint):longint;
var i:longint;
begin
  mi:=1;
  for i:=1 to b do mi:=mi*a;
end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),' ');
  readln(s);
  s1:='';
  j:=0;
  for i:=1 to length(s) do
    if s[i] in ['0'..'9'] then s1:=s1+s[i]
      else
        begin
          inc(j);
          val(s1,a[j]);
          b[j]:=s[i];
          s1:='';
        end;
  inc(j);
  val(s1,a[j]);
  n:=j;
  i:=0;
  while i<=n-1 do
    begin
      inc(i);
      if b[i]='^' then
        begin
          a[i]:=mi(a[i],a[i+1]);
          for j:=i+1 to n do a[j]:=a[j+1];
          for j:=i to n-1 do b[j]:=b[j+1];
          dec(n);
          dec(i);
        end;
    end;
  i:=0;
  while i<=n-1 do
    begin
      inc(i);
      if b[i] in ['*','/'] then
        begin
          if b[i]='*' then a[i]:=a[i]*a[i+1] else a[i]:=a[i] div a[i+1];
          for j:=i+1 to n do a[j]:=a[j+1];
          for j:=i to n-1 do b[j]:=b[j+1];
          dec(n);
          dec(i);
        end;
    end;
  i:=0;
  while i<=n-1 do
    begin
      inc(i);
      if b[i] in ['+','-'] then
        begin
          if b[i]='+' then a[i]:=a[i]+a[i+1] else a[i]:=a[i]-a[i+1];
          for j:=i+1 to n do a[j]:=a[j+1];
          for j:=i to n-1 do b[j]:=b[j+1];
          dec(n);
          dec(i);
        end;
    end;
  writeln(a[1]);
end.