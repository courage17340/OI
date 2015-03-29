var
  a:array[1..10] of longint;
  s:string;
  n,i,j,ans,k:longint;
function f(ch:char):longint;
begin
  if ch in ['0'..'9'] then exit(ord(ch)-48);
  exit(10);
end;
begin
  readln(s);
  fillchar(a,sizeof(a),0);
  for i:=1 to length(s) do
    if s[i]='?' then j:=i else a[i]:=f(s[i]);
  for i:=0 to 10 do
    begin
      ans:=0;
      for k:=1 to 10 do ans:=ans+(11-k)*a[k];
      ans:=ans+i*(11-j);
      if ans mod 11=0 then
        begin
          if i=10 then writeln('X') else writeln(i);
          halt;
        end;
    end;
  writeln(-1);
end.