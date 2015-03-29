var
  a,b:array[-100..100] of longint;
  i,j,m:longint;
  s:ansistring;
begin
  readln(s);
  m:=pos('.',s);
  fillchar(a,sizeof(a),0);fillchar(b,sizeof(b),0);
  if m=0
    then for i:=1 to length(s) do a[i]:=ord(s[length(s)-i+1])-48
    else
      begin
        for i:=1 to m-1 do a[i]:=ord(s[m-i])-48;
        delete(s,1,m);
        for i:=1 to length(s) do a[-i]:=ord(s[i])-48;
      end;
  readln(s);
  m:=pos('.',s);
  if m=0
    then for i:=1 to length(s) do b[i]:=ord(s[length(s)-i+1])-48
    else
      begin
        for i:=1 to m-1 do b[i]:=ord(s[m-i])-48;
        delete(s,1,m);
        for i:=1 to length(s) do b[-i]:=ord(s[i])-48;
      end;
  j:=0;
  for i:=-100 to -1 do
    begin
      a[i]:=a[i]+b[i]+j;
      j:=a[i] div 2;
      a[i]:=a[i] mod 2;
    end;
  for i:=1 to 100 do
    begin
      a[i]:=a[i]+b[i]+j;
      j:=a[i] div 2;
      a[i]:=a[i] mod 2;
    end;
  j:=100;
  while (a[j]=0)and(j>-100) do dec(j);
  if (j=-100)and(a[j]=0) then halt;
  write(j);
  for i:=j-1 downto -100 do if a[i]=1 then write(' ',i);
  writeln;
end.