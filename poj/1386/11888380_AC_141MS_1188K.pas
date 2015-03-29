var
  t,n,i,j,k,p:longint;
  s:ansistring;
  f,g:array[1..26] of longint;
  v:array[1..26] of boolean;
  flag:boolean;
function father(x:longint):longint;
begin
  father:=x;
  while x<>g[x] do x:=g[x];
  g[father]:=x;
  exit(x);
end;
begin
  readln(t);
  for k:=1 to t do
    begin
      readln(n);
      fillchar(f,sizeof(f),0);
      for i:=1 to 26 do g[i]:=i;
      fillchar(v,sizeof(v),0);
      for i:=1 to n do
        begin
          readln(s);
          inc(f[ord(s[1])-96]);
          dec(f[ord(s[length(s)])-96]);
          g[father(ord(s[1])-96)]:=father(ord(s[length(s)])-96);
          v[ord(s[1])-96]:=true;
          v[ord(s[length(s)])-96]:=true;
        end;
      flag:=true;
      for i:=1 to 26 do if v[i] then p:=father(i);
      for i:=1 to 26 do if v[i] and (father(i)<>p) then flag:=false;
      j:=0;
      for i:=1 to 26 do inc(j,abs(f[i]));
      if (j<=2) and flag then writeln('Ordering is possible.') else writeln('The door cannot be opened.');
    end;
end.