var
  a,b:array[1..300] of longint;
  s,t:ansistring;
  n,i,j,k,p:longint;
begin
  readln(n);
  for p:=1 to n do
    begin
      fillchar(a,sizeof(a),0);
      fillchar(b,sizeof(b),0);
      readln(s);
      t:=copy(s,1,pos(' ',s)-1);
      delete(s,1,pos(' ',s));
      while s[1]='0' do delete(s,1,1);
      while t[1]='0' do delete(t,1,1);
      while s[length(s)]='0' do delete(s,length(s),1);
      while t[length(t)]='0' do delete(t,length(t),1);
      for i:=301-length(s) to 300 do a[i]:=ord(s[301-i])-48;
      for i:=301-length(t) to 300 do b[i]:=ord(t[301-i])-48;
      for i:=1 to 300 do a[i]:=a[i]+b[i];
      j:=0;
      for i:=300 downto 1 do
        begin
          a[i]:=a[i]+j;
          j:=a[i] div 10;
          a[i]:=a[i] mod 10;
        end;
      j:=1;
      while (a[j]=0)and(j<300) do inc(j);
      k:=300;
      while (a[k]=0)and(k>j) do dec(k);
      for i:=k downto j do write(a[i]);
      writeln;
    end;
  readln;
end.