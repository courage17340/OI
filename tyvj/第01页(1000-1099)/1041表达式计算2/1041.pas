var
  a:array[1..300] of longint;
  n,i,j,m:longint;
  s:ansistring;
procedure solve(s:ansistring;m:longint);
var i,j:longint;
begin
  i:=301;
  if m=1 then
    begin
      while length(s)>0 do
        begin
          dec(i);
          a[i]:=a[i]+ord(s[length(s)])-48;
          delete(s,length(s),1);
        end;
      j:=0;
      for i:=300 downto 20 do
        begin
          a[i]:=a[i]+j;
          j:=a[i] div 10;
          a[i]:=a[i] mod 10;
        end;
      exit;
    end;
  while length(s)>0 do
    begin
      dec(i);
      a[i]:=a[i]-ord(s[length(s)])+48;
      delete(s,length(s),1);
    end;
  for i:=300 downto 20 do
    begin
      j:=0;
      while a[i]<0 do begin a[i]:=a[i]+10;j:=j+1;end;
      dec(a[i-1],j);
    end;
end;
begin
  readln(s);fillchar(a,sizeof(a),0);
  s:='+'+s;
  while length(s)>0 do
    begin
      if s[1]='-' then m:=-1 else m:=1;
      delete(s,1,1);
      i:=pos('+',s);
      j:=pos('-',s);
      if (i>j)and(j>0)or(i=0)and(j>0) then i:=j;
      if i=0 then i:=length(s)+1;
      solve(copy(s,1,i-1),m);
      delete(s,1,i-1);
    end;
  i:=1;
  while (i<300)and(a[i]=0) do inc(i);
  for j:=i to 300 do write(a[j]);
  writeln;
end.